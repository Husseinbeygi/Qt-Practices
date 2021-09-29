#ifndef ALBUMDAO_H
#define ALBUMDAO_H

class QSqlDatabase;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database);
    void init() const;
private:
    QSqlDatabase& m_Database;
};

#endif // ALBUMDAO_H
