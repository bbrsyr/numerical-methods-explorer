#pragma once


#include <QChartView>
#include "FunctionEvaluator.h"



class PlotWidget : public QChartView {
public :
    PlotWidget(QWidget* parent = nullptr);

    void plotFunction(FunctionEvaluator& f, double start, double end, double step);
};

