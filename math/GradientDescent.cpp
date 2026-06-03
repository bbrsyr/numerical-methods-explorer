#include "../include/GradientDescent.h"

GradientDescent::GradientDescent(std::unique_ptr<FunctionEvaluator> function,
                                 double initialGuess,
                                 double learningRate,
                                 double tolerance,
                                 int maxIterations)
                                : function(std::move(function)),
                                learningRate(learningRate),
                                tolerance(tolerance),
                                maxIterations(maxIterations){
    state.iteration = 0;
    state.x = initialGuess;
    state.fx = function->evaluate(initialGuess);
    state.derivative = function->derivative(initialGuess);
    state.error = std::abs(state.derivative);

    history.push_back(state);
}

void GradientDescent::step() {
    double x = state.x;
    double nabla_fx = function->derivative(x);

    state.derivative = nabla_fx;

    double next_x = x - (learningRate * nabla_fx);


    state.iteration++;

    state.x = next_x;
    state.fx = function->evaluate(next_x);
    state.derivative = function->derivative(next_x);
    state.error = std::abs(state.derivative);

    history.push_back(state);
}

bool GradientDescent::converged() const {
    return state.error < tolerance || state.iteration >= maxIterations;
}

IterationData GradientDescent::currentState() const {
    return state;
}


const std::vector<IterationData>& GradientDescent::getHistory() const {
    return history;
}