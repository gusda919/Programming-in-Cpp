#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public Component{
public:
    Resistor(std::string const _name, Connection* const _positive, Connection* const _negative, double const resistance);
    void simulate(double const _timeStep) override;
    double getCurrent() const override;
    ~Resistor() = default;
protected:
    double const resistance;
};

#endif
