#ifndef BATTERY_H
#define BATTERY_H

#include "Connection.h"
#include "Component.h"

class Battery : public Component{
public:
    Battery(std::string const _name, Connection* const _positive, Connection* const _negative, double _voltage);
    void simulate(double const _timeStep) override;
    double getCurrent() const override;
    ~Battery() = default;
protected:
    double voltage;
};

#endif
