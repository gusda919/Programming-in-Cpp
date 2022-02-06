#include "Battery.h"
#include "Component.h"

using namespace std;

Battery::Battery(string const _name, Connection* const _positive, Connection* const _negative, double _voltage)
: Component(_name, _positive, _negative), voltage{_voltage}
{
}

//positive sets to battery voltage and negative to 0
void Battery::simulate(double const _timeStep) {
   (void)_timeStep;

    positive->setVoltage(voltage);
    negative->setVoltage(0);
}

//always 0 in battery
double Battery::getCurrent() const {
    return 0;
}

