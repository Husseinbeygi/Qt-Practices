#include "MemoryWidget.h"
#include "QDebug"
using namespace QtCharts;

const int CHART_X_RANGE_COUNT = 50;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;
const int CHART_TOP_COLOR = 0xFFFFFF;
const int CHART_BOTTOM_COLOR = 0x000000;
const int CHART_PEN_COLOR = 0xa53921;
const int PEN_WIDTH = 3;


MemoryWidget::MemoryWidget(QWidget *parent): SysInfoWidget(parent),m_Series(new QLineSeries(this)),m_PointPositionX(0)
{
        QAreaSeries * AreaSeries = new QAreaSeries(m_Series);

        QPen pen(CHART_PEN_COLOR);
        pen.setWidth(PEN_WIDTH);

        QLinearGradient gradient(QPointF(0,0),QPointF(0,1));
        gradient.setColorAt(0.0, CHART_TOP_COLOR);
        gradient.setColorAt(1.0, CHART_BOTTOM_COLOR);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);

        AreaSeries->setPen(pen);
        AreaSeries->setBrush(gradient);

        QChart* chart = ChartView().chart();
        chart->addSeries(AreaSeries);
        chart->setTitle("Memory Used");
        chart->createDefaultAxes();
        chart->axisX()->visibleChanged(false);
        chart->axisX()->setRange(0,CHART_X_RANGE_MAX);
        chart->axisY()->setRange(0,100);

}
void MemoryWidget::UpdaterSeries()
{
    double MemoryUsage = SysInfo::instance().MemoryUsed();
    m_Series->append(m_PointPositionX++,MemoryUsage);
        if(m_Series->count() > CHART_X_RANGE_COUNT) {
            QChart* chart = ChartView().chart();
            chart->scroll(chart->plotArea().width() / CHART_X_RANGE_MAX,0);

            m_Series->remove(0);


        }
        qDebug() << "Series Count : "  <<m_Series->count();

}
