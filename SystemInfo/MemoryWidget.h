#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include "SysInfoWidget.h"
#include "SysInfo.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QGradient>
#include <QPen>

class MemoryWidget : public SysInfoWidget
{
public:
    explicit MemoryWidget(QWidget *parent = 0);

    // SysInfoWidget interface
protected slots:
    void UpdaterSeries() override;
private:
    QtCharts::QLineSeries * m_Series;
    qint64 m_PointPositionX;
};

#endif // MEMORYWIDGET_H
