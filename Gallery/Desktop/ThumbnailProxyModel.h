#ifndef THUMBNAILPROXYMODEL_H
#define THUMBNAILPROXYMODEL_H

#include <QIdentityProxyModel>
#include <QHash>
#include <QPixmap>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel
{
    Q_OBJECT
public:
    ThumbnailProxyModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index,int role) const override;
    void setSourceModel(QAbstractItemModel * SourceModel) override;
    PictureModel *pictureModel() const;
private:
    void GenerateThumbnail(const QModelIndex &startIndex,int Count);
    void ReloadThumbnails();

private:
    QHash<QString,QPixmap*> m_Thumbnails;

};

#endif // THUMBNAILPROXYMODEL_H
