#pragma once


#include "NumericalMethod.h"
#include "FunctionEvaluator.h"
#include "../include/PlotWidget.h"

class NewtonMethod : public NumericalMethod{
private:
    FunctionEvaluator* function;

    IterationData state;

    double tolerance;

    int maxIterations = 100;

    std::vector<IterationData> history;

public:
    NewtonMethod(FunctionEvaluator* function, double initialGuess, double tolerance = 1e-6, int maxIterations = 100);

    void step() override;

    bool converged() const override;

    IterationData currentState() const override;

    ~NewtonMethod() override = default;

    const std::vector<IterationData>& getHistory() const;

};


