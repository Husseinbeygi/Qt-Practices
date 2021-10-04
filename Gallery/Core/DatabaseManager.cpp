/*Database Includes*/
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

#include "DatabaseManager.h"
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

void DatabaseManager::DebugQuery(const QSqlQuery &query)
{
    if(query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:" << query.lastQuery();
    }else {
        qDebug() << "Query NOT OK:" << query.lastError().text();
        qDebug() << "Query Command:" << query.lastQuery();
    }
}

DatabaseManager::DatabaseManager(const QString &path):m_Database(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
                    ,albumDao(* m_Database)
                    ,pictureDao(* m_Database)

{
    m_Database->setDatabaseName(path);
    m_Database->open();

    albumDao.init();
    pictureDao.init();
}
