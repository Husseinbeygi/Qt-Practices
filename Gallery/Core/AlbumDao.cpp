#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>

#include "AlbumDao.h"
#include "Album.h"

AlbumDao::AlbumDao(QSqlDatabase &database) : m_Database(database)
{

}

void AlbumDao::init() const
{
    if(!m_Database.tables().contains("albums")){
        QSqlQuery query(m_Database);
        query.exec("CREATE TABLE albums (id INTEGER PRIMERY KEY AUTOINCREMENT,name TEXT)");
    }
}

void AlbumDao::AddAlbum(Album &album) const
{
    QSqlQuery query(m_Database);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name",album.Name());
    query.exec();
    album.SetId(query.lastInsertId().toInt());

}

void AlbumDao::UpdateAlbum(Album &album) const
{

   QSqlQuery query(m_Database);
    query.prepare("UPDATE albums (name) VALUES (:name)");
    query.bindValue(":name",album.Name());
    query.exec();
}
void AlbumDao::DeleteAlbum(int id) const
{
    QSqlQuery query(m_Database);
     query.prepare("DELETE albums WHERE (:id)");
     query.bindValue(":id",id);
     query.exec();
}

QVector<Album *> AlbumDao::albums() const
{

    QSqlQuery query("SELECT * FROM albums",m_Database);
    query.exec();
    QVector<Album *> list;
    while(query.next()) {
        Album* album = new Album();
        album->SetId(query.value("id").toInt());
        album->SetName(query.value("name").toString());
        list.append(album);
    }
    return list;



}
