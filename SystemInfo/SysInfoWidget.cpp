#include "SysInfoWidget.h"


SysInfoWidget::SysInfoWidget(QWidget *parent, int StartDelayms, int UpdaterSeriesDelayms) : QWidget(parent), m_ChartView(this)
{
    m_RefreshTimer.setInterval(UpdaterSeriesDelayms);
    connect(&m_RefreshTimer,&QTimer::timeout,this,&SysInfoWidget::UpdaterSeries);
    m_RefreshTimer.start(StartDelayms);

    m_ChartView.setRenderHint(QPainter::Antialiasing);
    m_ChartView.chart()->legend()->setVisible(false);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&m_ChartView);
    setLayout(layout);

}

QtCharts::QChartView &SysInfoWidget::ChartView()
{
    return m_ChartView;
}
