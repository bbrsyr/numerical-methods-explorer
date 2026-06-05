#pragma once


#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

#include "FunctionEvaluator.h"
#include "IterationData.h"



class PlotWidget : public QChartView {
public :
    PlotWidget(QWidget* parent = nullptr);

    void plotFunction(FunctionEvaluator& f, double start, double end, double step);

    void plotHistory(const std::vector<IterationData>& history);

    void plotNewtonSteps(const std::vector<IterationData>& history);
};

