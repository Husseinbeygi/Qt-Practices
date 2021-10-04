#include "AlbumModel.h"


AlbumModel::AlbumModel(QObject *parent):    QAbstractListModel(parent),
    m_Db(DatabaseManager::instance()),
    m_Albums(m_Db.albumDao.albums())
{

}

QModelIndex AlbumModel::AddAlbum(const Album &album)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Album> newAlbum(new Album(album));
    m_Db.albumDao.AddAlbum(*newAlbum);
    m_Albums->push_back(move(newAlbum));
    endInsertRows();
    return index(rowIndex, 0);
}

int AlbumModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Albums->size();;
}

QVariant AlbumModel::data(const QModelIndex &index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Album& album = *m_Albums->at(index.row());

    switch (role) {
        case Roles::IdRole:
            return album.Id();

        case Roles::NameRole:
        case Qt::DisplayRole:
            return album.Name();

        default:
            return QVariant();
    }
}

bool AlbumModel::isIndexValid(const QModelIndex &index) const
{
    if (index.row() < 0
            || index.row() >= rowCount()
            || !index.isValid()) {
        return false;
    }
    return true;
}
bool AlbumModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!isIndexValid(index)
            || role != Roles::NameRole) {
        return false;
    }
    Album& album = *m_Albums->at(index.row());
    album.SetName(value.toString());
    m_Db.albumDao.UpdateAlbum(album);
    emit dataChanged(index, index);
    return true;
}

bool AlbumModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0
            || row >= rowCount()
            || count < 0
            || (row + count) > rowCount()) {
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--) {
        const Album& album = *m_Albums->at(row + countLeft);
        m_Db.albumDao.DeleteAlbum(album.Id());
    }
    m_Albums->erase(m_Albums->begin() + row,
                  m_Albums->begin() + row + count);
    endRemoveRows();
    return true;

}

QHash<int, QByteArray> AlbumModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

