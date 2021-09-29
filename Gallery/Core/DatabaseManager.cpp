#include "DatabaseManager.h"
#include <QSqlDatabase>

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    m_Database->close();
    delete m_Database;
}

DatabaseManager::DatabaseManager(const QString &path):m_Database(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))

{
    m_Database->setDatabaseName(path);
    m_Database->open();
}
