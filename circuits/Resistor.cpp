#include "Resistor.h"

using namespace std;

Resistor::Resistor(string const _name, Connection* const _positive, Connection* const _negative, double const _resistance)
: Component{_name, _positive, _negative} , resistance{_resistance}
{
}

void Resistor::simulate(double const _timeStep) {
    double voltageMoved{(getVoltage() / resistance) * _timeStep};

    if (positive->getVoltage() < negative->getVoltage()){
        positive->setVoltage(positive->getVoltage() + voltageMoved);
        negative->setVoltage(negative->getVoltage() - voltageMoved);

    } else {
        negative->setVoltage(negative->getVoltage() + voltageMoved);
        positive->setVoltage(positive->getVoltage() - voltageMoved);
    }
}

double Resistor::getCurrent() const {
    return (getVoltage() / resistance);
}


