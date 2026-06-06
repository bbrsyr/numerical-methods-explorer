#include "../include/PlotWidget.h"

#include <QChart>
#include <QLineSeries>
#include <QScatterSeries>


PlotWidget::PlotWidget(QWidget* parent) : QChartView(parent){

    QChart* chart = new QChart();

    setChart(chart);

    chart->setTitle("Function Plot");
}

void PlotWidget::plotFunction(FunctionEvaluator& f, double start, double end, double step) {
    QChart* chart = new QChart();

    QLineSeries* series = new QLineSeries();

    for(double x = start; x <= end; x += step) {
        series->append(x, f.evaluate(x));
    }

    chart->addSeries(series);

    chart->createDefaultAxes();

    setChart(chart);
}

void PlotWidget::plotHistory(const std::vector<IterationData>& history) {

    QScatterSeries* series = new QScatterSeries();

    for (const auto& step : history) {
        series->append(step.x, step.fx);
    }

    chart()->addSeries(series);

    series->attachAxis(chart()->axes(Qt::Horizontal).first());
    series->attachAxis(chart()->axes(Qt::Vertical).first());

    QLineSeries* path = new QLineSeries();

    for (const auto& step : history) {
        path->append(step.x, step.fx);
    }

    chart()->addSeries(path);

    path->attachAxis(chart()->axes(Qt::Horizontal).first());
    path->attachAxis(chart()->axes(Qt::Vertical).first());

}

void PlotWidget::plotNewtonStep(const std::vector<IterationData>& history, int iteration) {
    if (iteration >= history.size()) return;

    auto* xAxis = chart()->axes(Qt::Horizontal).first();
    auto* yAxis = chart()->axes(Qt::Vertical).first();

    const auto& current = history[iteration];
    const auto& next = history[iteration + 1];

    QLineSeries* tangent = new QLineSeries();
    tangent->setColor(Qt::green);

    tangent->append(current.x, current.fx);
    tangent->append(next.x, 0);

    chart()->addSeries(tangent);

    tangent->attachAxis(xAxis);
    tangent->attachAxis(yAxis);

    QLineSeries* vertical = new QLineSeries();
    QPen verticalPen;
    verticalPen.setStyle(Qt::DashLine);

    vertical->setPen(verticalPen);

    vertical->append(next.fx, 0);
    vertical->append(next.x,next.fx);

    chart()->addSeries(vertical);

    vertical->attachAxis(xAxis);
    vertical->attachAxis(yAxis);

}

void PlotWidget::plotNewtonSteps(const std::vector<IterationData>& history, int currentIteration) {
    if (history.size() < 2) return;

    auto* xAxis = chart()->axes(Qt::Horizontal).first();
    auto* yAxis = chart()->axes(Qt::Vertical).first();

    for (size_t i = 0; i < currentIteration; i++) {
        const auto& current = history[i];
        const auto& next = history[i + 1];

        QLineSeries* tangent = new QLineSeries();
        tangent->setColor(Qt::green);

        tangent->append(current.x, current.fx);
        tangent->append(next.x, 0);

        chart()->addSeries(tangent);

        tangent->attachAxis(xAxis);
        tangent->attachAxis(yAxis);

        QLineSeries* vertical = new QLineSeries();

        QPen verticalPen;
        verticalPen.setStyle(Qt::DashLine);
        vertical->setPen(verticalPen);


        vertical->append(next.x, 0);
        vertical->append(next.x, next.fx);

        chart()->addSeries(vertical);

        vertical->attachAxis(xAxis);
        vertical->attachAxis(yAxis);
    }
}

void PlotWidget::clear() {
    chart()->removeAllSeries();
}
























