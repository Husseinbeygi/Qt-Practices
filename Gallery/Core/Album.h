#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "Core_global.h"


class CORE_EXPORT Album
{
public:
    explicit Album(const QString &name = "");

    int Id() const;
    void SetId(int id);
    QString Name() const;
    void SetName(const QString  &name);

private:
    int m_Id;
    QString m_Name;

};

#endif // ALBUM_H
