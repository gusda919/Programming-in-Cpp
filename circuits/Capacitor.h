#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"

class Capacitor : public Component {
public:
    Capacitor(std::string const _name, Connection* const _positive, Connection* const _negative, double const _capacitance);
    void simulate(double const _timeStep) override;
    double getCurrent() const override;
    ~Capacitor() = default;

protected:
    double const capacitance;
    double internalCharge;

};

#endif
