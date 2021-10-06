#include "AlbumWidget.h"
#include "ui_AlbumWidget.h"

#include <QInputDialog>
#include <QFileDialog>

#include "AlbumModel.h"
#include "PictureModel.h"
#include "ThumbnailProxyModel.h"

#include <PictureDelegate.h>

AlbumWidget::AlbumWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumWidget),
    m_AlbumModel(nullptr),
    m_AlbumSelectionModel(nullptr),
    m_PictureModel(nullptr),
    m_PictureSelectionModel(nullptr)
{
    ui->setupUi(this);
    ClearUi();
    ui->thumbnailListView->setSpacing(5);
    ui->thumbnailListView->setResizeMode(QListView::Adjust);
    ui->thumbnailListView->setFlow(QListView::LeftToRight);
    ui->thumbnailListView->setWrapping(true);
    ui->thumbnailListView->setItemDelegate(new PictureDelegate(this));

    connect(ui->thumbnailListView, &QListView::doubleClicked,
            this, &AlbumWidget::pictureActivated);

    connect(ui->deleteButton, &QPushButton::clicked,
            this, &AlbumWidget::deleteAlbum);

    connect(ui->editButton, &QPushButton::clicked,
            this, &AlbumWidget::editAlbum);

    connect(ui->addPictursButton, &QPushButton::clicked,
            this, &AlbumWidget::addPictures);
}

AlbumWidget::~AlbumWidget()
{
    delete ui;
}

void AlbumWidget::setAlbumModel(AlbumModel *albumModel)
{
    m_AlbumModel = albumModel;

      connect(m_AlbumModel, &QAbstractItemModel::dataChanged, [this] (const QModelIndex &topLeft) {
          if (topLeft == m_AlbumSelectionModel->currentIndex()) {
              loadAlbum(topLeft);
          }
      });
}

void AlbumWidget::setAlbumSelectionModel(QItemSelectionModel *albumSelectionModel)
{
    m_AlbumSelectionModel = albumSelectionModel;

    connect(m_AlbumSelectionModel, &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        if (selected.isEmpty()) {
            ClearUi();
            return;
        }
        loadAlbum(selected.indexes().first());
    });
}

void AlbumWidget::setPictureModel(ThumbnailProxyModel *pictureModel)
{
    m_PictureModel = pictureModel;
    ui->thumbnailListView->setModel(pictureModel);

}

void AlbumWidget::setPictureSelectionModel(QItemSelectionModel *selectionModel)
{
    ui->thumbnailListView->setSelectionModel(selectionModel);

}

void AlbumWidget::deleteAlbum()
{
    if (m_AlbumSelectionModel->selectedIndexes().isEmpty()) {
            return;
        }
        int row = m_AlbumSelectionModel->currentIndex().row();
        m_AlbumModel->removeRow(row);

        // Try to select the previous album
        QModelIndex previousModelIndex = m_AlbumModel->index(row - 1, 0);
        if(previousModelIndex.isValid()) {
            m_AlbumSelectionModel->setCurrentIndex(previousModelIndex, QItemSelectionModel::SelectCurrent);
            return;
        }

        // Try to select the next album
        QModelIndex nextModelIndex = m_AlbumModel->index(row, 0);
        if(nextModelIndex.isValid()) {
            m_AlbumSelectionModel->setCurrentIndex(nextModelIndex, QItemSelectionModel::SelectCurrent);
            return;
        }
}

void AlbumWidget::editAlbum()
{
    if (m_AlbumSelectionModel->selectedIndexes().isEmpty()) {
            return;
        }
        QModelIndex currentAlbumIndex = m_AlbumSelectionModel->selectedIndexes().first();
        QString oldAlbumName = m_AlbumModel->data(currentAlbumIndex, AlbumModel::Roles::NameRole).toString();

        bool ok;
        QString newName = QInputDialog::getText(this,
                                                "Album's name",
                                                "Change Album name",
                                                QLineEdit::Normal,
                                                oldAlbumName,
                                                &ok);

        if (ok && !newName.isEmpty()) {
            m_AlbumModel->setData(currentAlbumIndex, newName, AlbumModel::Roles::NameRole);
        }
}

void AlbumWidget::addPictures()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,
                                                          "Add pictures",
                                                          QDir::homePath(),
                                                          "Picture files (*.jpg *.png)");
    if (!filenames.isEmpty()) {
        QModelIndex lastModelIndex;
        for (auto filename : filenames) {
            Picture picture(filename);
            lastModelIndex = m_PictureModel->pictureModel()->addPicture(picture);
        }
        lastModelIndex = m_PictureModel->index(lastModelIndex.row(), 0);
        ui->thumbnailListView->setCurrentIndex(lastModelIndex);
    }
}

void AlbumWidget::ClearUi()
{
    ui->albumname->setText("");
    ui->deleteButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->addPictursButton->setVisible(false);

}

void AlbumWidget::loadAlbum(const QModelIndex &albumIndex)
{
    m_PictureModel->pictureModel()->setAlbumId(m_AlbumModel->data(albumIndex, AlbumModel::Roles::IdRole).toInt());
    ui->albumname->setText(m_AlbumModel->data(albumIndex, Qt::DisplayRole).toString());
    ui->deleteButton->setVisible(true);
    ui->editButton->setVisible(true);
    ui->addPictursButton->setVisible(true);

}
