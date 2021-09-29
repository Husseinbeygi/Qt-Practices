#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <AlbumDao.h>

#include <QString>

class QSqlDatabase;
const QString DATABASE_NAME = "gallery.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();


protected:
    DatabaseManager(const QString& path = DATABASE_NAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    QSqlDatabase* m_Database;

public:
    const AlbumDao albumDao;

};

#endif // DATABASEMANAGER_H
