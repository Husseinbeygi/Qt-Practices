#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:
    SysInfo();
    virtual ~SysInfo();

    virtual void init() = 0;
    virtual double CpuLoadAverage() = 0;
    virtual double MemoryUsed() = 0;


};

#endif // SYSINFO_H
