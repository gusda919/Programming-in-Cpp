#ifndef CONNECTION_H
#define CONNECTION_H

class Connection {
public:
    Connection();
    ~Connection()= default;
    void setVoltage(const double volt);
    double getVoltage() const;
protected:
    double voltage;
};

#endif
