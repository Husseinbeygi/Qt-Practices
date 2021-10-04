#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>


#include "AlbumDao.h"
#include "Album.h"
#include "DatabaseManager.h"

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
    DatabaseManager::DebugQuery(query);

}

void AlbumDao::UpdateAlbum(Album &album) const
{

    QSqlQuery query(m_Database);
    query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", album.Name());
    query.bindValue(":id", album.Id());
    query.exec();
    DatabaseManager::DebugQuery(query);

}
void AlbumDao::DeleteAlbum(int id) const
{
    QSqlQuery query(m_Database);
     query.prepare("DELETE albums WHERE (:id)");
     query.bindValue(":id",id);
     query.exec();
     DatabaseManager::DebugQuery(query);

}



unique_ptr<vector<unique_ptr<Album>>> AlbumDao::albums() const
{

    QSqlQuery query("SELECT * FROM albums",m_Database);
    query.exec();
    unique_ptr<vector<unique_ptr<Album>>> list(new vector<unique_ptr<Album>>);
    while(query.next()) {
        unique_ptr<Album> album(new Album());
        album->SetId(query.value("id").toInt());
        album->SetName(query.value("name").toString());
        list->push_back(move(album));
    }
    return list;
}
