#include "../include/PlotWidget.h"

#include <QChart>
#include <QLineSeries>




PlotWidget::PlotWidget(QWidget* parent) : QChartView(parent){

    QChart* chart = new QChart();

    setChart(chart);

    chart->setTitle("Function Plot");
}

void PlotWidget::plotFunction(FunctionEvaluator& f, double start, double end, double step) {
    QLineSeries* line = new QLineSeries();

    for (double x = start; x <= end; x += step) {
        double y = f.evaluate(x);
        line->append(x, y);
    }

    chart()->removeAllSeries();
    chart()->addSeries(line);
    chart()->createDefaultAxes();
}
