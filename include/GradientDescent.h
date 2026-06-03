#pragma once


#include "../include/NumericalMethod.h"
#include "../include/FunctionEvaluator.h"


class GradientDescent : NumericalMethod {
private:
    std::unique_ptr<FunctionEvaluator> function;

    IterationData state;

    double gradient;

    double tolerance = 1e-6;

    double learningRate = 0.01;

    int maxIterations = 1000;

    std::vector<IterationData> history;

public:
    GradientDescent(
        FunctionEvaluator* function,
        double initialGuess,
        double learningRate = 0.01,
        double tolerance = 1e-6,
        int maxIterations = 1000
        );

    void step() override;

    bool converged() const override;

    IterationData currentState() const override;

    ~GradientDescent() override = default;

    const std::vector<IterationData>& getHistory() const;
};


