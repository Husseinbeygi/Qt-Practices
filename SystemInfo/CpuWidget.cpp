#include "CpuWidget.h"
#include <SysInfo.h>


using namespace QtCharts;


CpuWidget::CpuWidget(QWidget *parent): SysInfoWidget(parent),m_Series(new QPieSeries(this))
{

        m_Series->setHoleSize(0.35);
        m_Series->append("CpuLoad",30.0);
        m_Series->append("CpuFree",70.0);

        QChart *chart = ChartView().chart();
        chart->addSeries(m_Series);
        chart->setTitle("Cpu Average Load");
}

void CpuWidget::UpdaterSeries()
{
    double CpuLoadAverage = SysInfo::instance().CpuLoadAverage();
    m_Series->clear();
    m_Series->append("Load",CpuLoadAverage);
    m_Series->append("Free",100.0 - CpuLoadAverage);
}
