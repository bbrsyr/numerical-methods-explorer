#pragma once

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
