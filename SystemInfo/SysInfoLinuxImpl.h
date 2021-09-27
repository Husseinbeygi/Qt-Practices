#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include <QtGlobal>
#include <QVector>


#include "SysInfo.h"

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();

    // SysInfo interface
public:
    void init() override;
    double CpuLoadAverage() override;
    double MemoryUsed() override;

private:
    QVector<qulonglong> CpuRawData();
    QVector<qulonglong> m_CpuLoadLastValue;

};

#endif // SYSINFOLINUXIMPL_H
