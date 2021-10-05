#include "AlbumListWidget.h"
#include "ui_AlbumListWidget.h"
#include "AlbumModel.h"
#include <QInputDialog>

AlbumListWidget::AlbumListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlbumListWidget),m_AlbumModel(nullptr)
{
    ui->setupUi(this);

    connect(ui->btn_CreateAlbum,&QPushButton::clicked,this,&AlbumListWidget::CreateAlbum);
}

AlbumListWidget::~AlbumListWidget()
{
    delete ui;
}

void AlbumListWidget::SetModel(AlbumModel *Model)
{
    m_AlbumModel = Model;
    ui->AlbumList->setModel(m_AlbumModel);
}

void AlbumListWidget::SetSelectionModel(QItemSelectionModel *SelectionModel)
{
    ui->AlbumList->setSelectionModel(SelectionModel);
}

void AlbumListWidget::CreateAlbum()
{
    if (!m_AlbumModel) {
        return;
    }

    bool ok;
    QString albumname = QInputDialog::getText(this,"Create a new Album",
                                              "Choose an name",
                                              QLineEdit::Normal,
                                              "New album",
                                              &ok);
    if(ok && !albumname.isEmpty()) {
        Album album(albumname);
        QModelIndex CreatedIndex = m_AlbumModel->AddAlbum(album);
        ui->AlbumList->setCurrentIndex(CreatedIndex);
    }
}
