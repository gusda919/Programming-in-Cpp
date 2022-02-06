#include "Connection.h"

Connection::Connection() : voltage{0}
{
}

void Connection::setVoltage(const double volt){
    voltage = volt;
}

double Connection::getVoltage() const{
    return voltage;
}
