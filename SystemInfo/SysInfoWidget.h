#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QVBoxLayout>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr,int StartDelayms = 500,int UpdaterSeriesDelayms = 500);

protected:
    QtCharts::QChartView &ChartView();
protected slots:
    virtual void UpdaterSeries() = 0;
private:
    QTimer m_RefreshTimer;
    QtCharts::QChartView m_ChartView;
};

#endif // SYSINFOWIDGET_H
