#include "../include/FunctionEvaluator.h"

FunctionEvaluator::FunctionEvaluator() {
    parser.DefineVar("x", &xValue);
}

bool FunctionEvaluator::setExpression(const std::string& expr) {
    try {

        parser.SetExpr(expr);
        return true;

    } catch (...) {

        return false;

    }
}

double FunctionEvaluator::evaluate(double x) {
    xValue = x;
    return parser.Eval();
}

double FunctionEvaluator::derivative(double x) {
    double h = 1e-6;

    return (evaluate(x + h) - evaluate(x - h)) / (2 * h);
}