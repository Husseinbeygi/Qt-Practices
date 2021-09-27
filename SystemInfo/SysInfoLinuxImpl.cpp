#include "SysInfoLinuxImpl.h"

#include <sys/sysinfo.h>
#include <sys/types.h>
#include <QFile>

SysInfoLinuxImpl::SysInfoLinuxImpl() : SysInfo(),m_CpuLoadLastValue()
{

}

void SysInfoLinuxImpl::init()
{
    m_CpuLoadLastValue = CpuRawData();
}

double SysInfoLinuxImpl::CpuLoadAverage()
{
    QVector<qulonglong> FirstSample = m_CpuLoadLastValue;
    QVector<qulonglong> SecondSample = CpuRawData();
    m_CpuLoadLastValue = SecondSample;

    double overall = (SecondSample[0] - FirstSample[0])
            +(SecondSample[1] - FirstSample[1])
            +(SecondSample[2] - FirstSample[2]);

    double Total = overall +(SecondSample[3] - FirstSample[3]);
    double Percent = (overall / Total) * 100.0;
    return qBound(0.0,Percent,100.0);
}

double SysInfoLinuxImpl::MemoryUsed()
{
    struct sysinfo meminfo;
    sysinfo(&meminfo);

    qulonglong totalmemory = meminfo.totalram;
    totalmemory += meminfo.totalswap;
    totalmemory *= meminfo.mem_unit;

    qulonglong TotalMemoryUsed = meminfo.totalram - meminfo.freeram;
    TotalMemoryUsed += meminfo.totalswap - meminfo.freeswap;
    TotalMemoryUsed *= meminfo.mem_unit;

    double percent = (double)TotalMemoryUsed /
            (double) totalmemory * 100.0;
    return qBound(0.0,percent,100.0);
}

QVector<qulonglong> SysInfoLinuxImpl::CpuRawData()
{
    QFile procfile("/proc/stat");
    procfile.open(QIODevice::ReadOnly);
    QByteArray line = procfile.readLine();
    procfile.close();
    qulonglong TotalSystem = 0,TotalUserNice = 0,
            TotalUser = 0,TotalIdle = 0;
    std::sscanf(line.data(),"cpu %llu %llu %llu %llu",&TotalUser,&TotalUserNice,&TotalSystem,&TotalIdle);
    QVector<qulonglong> RawData;
    RawData.append(TotalUser);
    RawData.append(TotalUserNice);
    RawData.append(TotalSystem);
    RawData.append(TotalIdle);

    return RawData;
}
