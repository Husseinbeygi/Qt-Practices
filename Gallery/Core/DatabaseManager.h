#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QString>

class qSqlDatabase;
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
    qSqlDatabase* m_Database;
};

#endif // DATABASEMANAGER_H
