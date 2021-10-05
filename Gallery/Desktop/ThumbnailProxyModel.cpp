#include "ThumbnailProxyModel.h"
#include "PictureModel.h"

const unsigned int THUMBNAIL_SIZE = 350;

ThumbnailProxyModel::ThumbnailProxyModel(QObject *parent)
{

}

QVariant ThumbnailProxyModel::data(const QModelIndex &index, int role) const
{

}

void ThumbnailProxyModel::setSourceModel(QAbstractItemModel *SourceModel)
{
    QIdentityProxyModel::setSourceModel(SourceModel);
    if (!SourceModel) {
        return;
    }
    connect(SourceModel,&QAbstractItemModel::modelReset,[this]{ReloadThumbnails();});
    connect(SourceModel,&QAbstractItemModel::rowsInserted,[this](const QModelIndex &parent,int first,int last){GenerateThumbnail(index(0,1),last - first +1);});

}

PictureModel *ThumbnailProxyModel::pictureModel() const
{
    return static_cast<PictureModel*>(sourceModel());
}


void ThumbnailProxyModel::GenerateThumbnail(const QModelIndex &startIndex, int Count)
{
    if(!startIndex.isValid()) {
        return;
    }

    const QAbstractItemModel *model = startIndex.model();
    int lastindex = startIndex.row() + Count;
    for(int row = startIndex.row() ; row < lastindex ; row++) {
        QString filepath = model->data(model->index(row,0),PictureModel::Roles::FilePathRole).toString();
        QPixmap pixmap(filepath);
        auto Thumbnail = new QPixmap(pixmap.scaled(THUMBNAIL_SIZE,THUMBNAIL_SIZE,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        m_Thumbnails.insert(filepath,Thumbnail);
    }


}

void ThumbnailProxyModel::ReloadThumbnails()
{
    qDeleteAll(m_Thumbnails);
    m_Thumbnails.clear();
    GenerateThumbnail(index(0,0),rowCount());
}
