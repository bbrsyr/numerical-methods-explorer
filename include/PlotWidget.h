#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H


class PlotWidget : public QtCharts/QChartView {
public :
    PlotWidget(QWidget* parent = nullptr);

    void plotFunction();
};

#endif // PLOTWIDGET_H
