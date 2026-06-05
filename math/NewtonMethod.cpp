#include "../include/NewtonMethod.h"

NewtonMethod::NewtonMethod(FunctionEvaluator* function,
                           double initialGuess,
                           double tolerance,
                           int maxIterations)
    : function(function), tolerance(tolerance), maxIterations(maxIterations){
    state.iteration = 0;
    state.x = initialGuess;
    state.fx = function->evaluate(initialGuess);
    state.derivative = function->derivative(initialGuess);
    state.error = std::abs(state.fx);

    history.push_back(state);
}

void NewtonMethod::step() {
    double x = state.x;

    double fx = function->evaluate(x);
    double dfx = function->derivative(x);

    if (std::abs(dfx) < 1e-12)
    {
        state.error = tolerance;
        return;
    }


    double next_x = x - fx / dfx;

    state.iteration++;

    state.x = next_x;
    state.fx = function->evaluate(next_x);
    state.derivative = function->derivative(next_x);
    state.error = std::abs(next_x - x);

    history.push_back(state);
}

bool NewtonMethod::converged() const {
    return state.error < tolerance || state.iteration >= maxIterations;
}

IterationData NewtonMethod::currentState() const {
    return state;
}

const std::vector<IterationData>& NewtonMethod::getHistory() const {
    return history;
}

