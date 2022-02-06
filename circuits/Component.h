#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Connection.h"

class Component {
public:
    Component(std::string const _name, Connection* const _positive, Connection* const _negative);
    virtual void simulate(double const _timeStep) = 0;
    virtual double getCurrent() const = 0;
    double getVoltage() const;
    std::string getName() const;
    virtual ~Component() = default; 


protected:
    std::string name{};
    Connection* positive{};
    Connection* negative{};
   
};

#endif
