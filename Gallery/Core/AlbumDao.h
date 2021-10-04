#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <QVector>
#include <memory>

using namespace std;

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database);
    void init() const;

    void AddAlbum(Album& album) const;
    void UpdateAlbum(Album& album) const;
    void DeleteAlbum(int id) const;

//    QVector<Album*> albums() const;
    unique_ptr<vector<unique_ptr<Album>>> albums() const;
private:
    QSqlDatabase& m_Database;
};

#endif // ALBUMDAO_H
