#ifndef PICTURE_H
#define PICTURE_H

#include <QString>
#include <QUrl>
#include "Core_global.h"

class CORE_EXPORT Picture
{
public:
    Picture(const QString &FilePath = "");
    Picture(const QUrl &Fileurl);

    int Id() const;
    void SetId(int id);

    int AlbumId() const;
    int SetAlbumId(int albumid);

    QUrl FileUrl() const;
    void SetFileUrl (const QUrl &url);

private:
    int m_Id;
    int m_Albumid;
    QUrl m_FileUrl;
};

#endif // PICTURE_H
