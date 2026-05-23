#ifndef NUMERICALMETHOD_H
#define NUMERICALMETHOD_H

#endif // NUMERICALMETHOD_H

#include "IterationData.h"

class NumericalMethod {
public:
    virtual void step() = 0;
    virtual bool converged() const = 0;

    virtual IterationData currentState() const = 0;

    virtual ~NumericalMethod() = default;
};
