#include "Capacitor.h"

using namespace std;

Capacitor::Capacitor(string const _name, Connection* const _positive, Connection* const _negative, double const _capacitance)
: Component{_name, _positive, _negative}, capacitance{_capacitance}, internalCharge{0}
{
}

void Capacitor::simulate(double const _timeStep) {
    double movedVoltage{capacitance * abs(internalCharge - getVoltage()) * _timeStep};
    internalCharge += movedVoltage;

    if(positive->getVoltage() < negative->getVoltage()){
        positive->setVoltage(positive->getVoltage() + movedVoltage);
        negative->setVoltage(negative->getVoltage() - movedVoltage);
    } else {
        negative->setVoltage(negative->getVoltage() + movedVoltage);
        positive->setVoltage(positive->getVoltage() - movedVoltage);
    }
}

double Capacitor::getCurrent() const {
    return(capacitance * (getVoltage() - internalCharge));
}
