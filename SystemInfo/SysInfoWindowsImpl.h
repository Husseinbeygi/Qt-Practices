#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include "SysInfo.h"

class SysInfoWindowsImpl : public SysInfo
{
public:
    SysInfoWindowsImpl();


    // SysInfo interface
public:
    void init() override;
    double CpuLoadAverage() override;
    double MemoryUsed() override;
};

#endif // SYSINFOWINDOWSIMPL_H
