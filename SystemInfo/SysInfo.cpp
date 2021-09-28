#include "SysInfo.h"
#include <QtGlobal>
#include "SysInfoLinuxImpl.h"

SysInfo &SysInfo::instance()
{
    static SysInfoLinuxImpl singleton;
    return singleton;
}

SysInfo::~SysInfo()
{

}
SysInfo::SysInfo()
{


}

