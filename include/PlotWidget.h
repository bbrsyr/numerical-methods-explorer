#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#pragma once

#include <QtCharts/QChartView>


class PlotWidget : public QtCharts/QChartView {
public :
    PlotWidget(QWidget* parent = nullptr);

    void plotFunction();
};

#endif // PLOTWIDGET_H
