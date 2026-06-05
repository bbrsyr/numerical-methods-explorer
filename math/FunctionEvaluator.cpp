#include "../include/FunctionEvaluator.h"

FunctionEvaluator::FunctionEvaluator() {
    parser.DefineVar("x", &xValue);
}

bool FunctionEvaluator::setExpression(const std::string& expr) {
    try {

        parser.SetExpr(expr);
        return true;

    } catch (mu::Parser::exception_type& e) {

        std::cerr << e.GetMsg() << std::endl;
        return false;

    }
}

double FunctionEvaluator::evaluate(double x) {
    xValue = x;
    return parser.Eval();
}

double FunctionEvaluator::derivative(double x) {

    return (evaluate(x + h) - evaluate(x - h)) / (2 * h);
}