#ifndef FUNCTIONEVALUATOR_H
#define FUNCTIONEVALUATOR_H

#endif // FUNCTIONEVALUATOR_H

#include <string>
#include <muParser.h>


class FunctionEvaluator{
private:
    mu::Parser parser;

    double xValue;

public:
    FunctionEvaluator();

    bool setExpression(const std::string& expr);

    double evaluate(double x);

    double derivative(double x);
};
