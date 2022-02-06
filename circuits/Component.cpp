#include "Component.h"

using namespace std;

Component::Component(string const _name, Connection* const _positive, Connection* const _negative)
    : name{_name}, positive{_positive}, negative{_negative} 
{
}

void Component::simulate(double const _timeStep){
    (void)_timeStep;
}

double Component::getCurrent() const {
    return 0;
}

double Component::getVoltage() const {
    return abs(positive->getVoltage() - negative->getVoltage());
}

string Component::getName()const{
    return name;
}

