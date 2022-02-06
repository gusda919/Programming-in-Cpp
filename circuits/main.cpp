#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

void circuit1( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage);
void circuit2( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage);
void circuit3( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage);
void clear(const vector<Component*> & circuit);

//print simulations
void print( vector<Component*> const& circuit,  int const& iterations,  int const&  printedLines,  double const&  timeStep)
{

    //print header names
    for(Component* c : circuit){
        cout << setw(15) << c->getName();
    }
    
     cout << endl;
    
    //print Volt and Curr
    for(Component* c : circuit){
        (void)c;
        cout << setw(8) << "Volt" << setw(7) << "Curr";
    }

    cout << endl;

    //print stated amount of the last rows
    for(int i = 1; i <= iterations; i++){

        //simulate the rows, function in Resistor
        for (Component* c : circuit) {
            c->simulate(timeStep);
        }

        //if i divided by 20 000 equals a whole int then print the values
        if (i % (iterations / printedLines) == 0) {
            
            //print values of the different rows
            for (Component* c : circuit) {
                cout << fixed << setprecision(2) << setw(8) << c->getVoltage() << setw(7) << c->getCurrent();
            }
            cout << endl;

        }
    }
}

void circuit1( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage){
    Connection p, n, r124, r23;
    vector<Component*> circuit{};
    circuit.push_back(new Battery("Bat",  &p, &n, voltage));
    circuit.push_back(new Resistor("R1", &p, &r124, 6.0));
    circuit.push_back(new Resistor("R2", &r124, &r23, 4.0));
    circuit.push_back(new Resistor("R3", &r23, &n, 8.0));
    circuit.push_back(new Resistor("R4", &r124, &n, 12.0));
    print(circuit , iterations, printedLines, timeStep);
    cout << endl;
    clear(circuit);
}

void circuit2( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage){
    Connection p, n, l, r;
    vector<Component*> circuit{};
    circuit.push_back(new Battery("Bat", &p, &n, voltage));
    circuit.push_back(new Resistor("R1", &p, &l, 150.0));
    circuit.push_back(new Resistor("R2", &p, &r, 50.0));
    circuit.push_back(new Resistor("R3", &l, &r, 100.0));
    circuit.push_back(new Resistor("R4", &l, &n, 300.0));
    circuit.push_back(new Resistor("R5", &r, &n, 250.0));
    print(circuit, iterations, printedLines, timeStep);
    cout << endl;
    clear(circuit);
}

void circuit3( int const&  iterations, int const&  printedLines, double const&  timeStep, double const&  voltage){
    Connection p, n, l, r;
    vector<Component*>  circuit{};
    circuit.push_back(new Battery("Bat", &p, &n, voltage));
    circuit.push_back(new Resistor("R1", &p, &l, 150.0));
    circuit.push_back(new Resistor("R2", &p, &r, 50.0));
    circuit.push_back(new Capacitor("C1", &l, &r, 1.0));
    circuit.push_back(new Resistor("R4", &l, &n, 300.0));
    circuit.push_back(new Capacitor("C2", &r, &n, 0.75));
    print(circuit, iterations, printedLines, timeStep);
    cout << endl;
    clear(circuit);
}

//avoid leaks
void clear( const vector<Component*> & circuit){
 
    for (Component* c : circuit) {
            delete(c);
        }
       
}

int main(int argc, char **argv){
    int iterations{};
    int printedLines{};
    double timeStep{};
    double voltage{};


        //if the amount of arguments (5) are correct
        if(argc == 5){
            try {
            //convert to correct variable from string
             iterations = {stoi(argv[1])};
             printedLines = {stoi(argv[2])};
             timeStep = {stod(argv[3])};
             voltage = {stod(argv[4])};

            } catch(invalid_argument& e) {
                cout << "Invalid type of arguments, should be int, int, double, double. For example: './a.out 200000 10 0.01 24'" << endl;
                return -1;
            }
            
            //create circuits
            circuit1(iterations, printedLines, timeStep, voltage);
            circuit2(iterations, printedLines, timeStep, voltage);
            circuit3(iterations, printedLines, timeStep, voltage);
        } else {
            cout << "Invalid amount of arguments. Command line should contain 5 arguments. For example: './a.out 200000 10 0.01 24'" << endl;
        }
       
}