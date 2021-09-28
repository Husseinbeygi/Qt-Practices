#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QtCharts/QPieSeries>

#include "SysInfoWidget.h"

class CpuWidget : public SysInfoWidget
{

    Q_OBJECT
public:
    explicit CpuWidget(QWidget* parent = 0);

    // SysInfoWidget interface
protected slots:
    void UpdaterSeries() override;

private:
    QtCharts::QPieSeries* m_Series;
};

#endif // CPUWIDGET_H
