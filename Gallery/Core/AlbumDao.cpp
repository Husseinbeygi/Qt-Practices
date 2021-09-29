#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>

#include "AlbumDao.h"
AlbumDao::AlbumDao(QSqlDatabase &database) : m_Database(database)
{

}

void AlbumDao::init() const
{
    if(!m_Database.tables().contains("album")){
        QSqlQuery query(m_Database);
        query.exec("CREATE TABLE album (id INTEGER PRIMERY KEY AUTOINCREMENT,name TEXT)");
    }
}
