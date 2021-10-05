#include "Picture.h"

Picture::Picture(const QString &FilePath) : Picture(QUrl::fromLocalFile(FilePath))
{

}

Picture::Picture(const QUrl &Fileurl):m_Id(-1),m_Albumid(-1),m_FileUrl(Fileurl)
{

}

int Picture::Id() const
{

}

void Picture::SetId(int id)
{

}

int Picture::AlbumId() const
{

}

int Picture::SetAlbumId(int albumid)
{

}

QUrl Picture::FileUrl() const
{
    return m_FileUrl;
}

void Picture::SetFileUrl(const QUrl &url)
{
    m_FileUrl = url;
}
