// August_Koehler_hw4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "Circuit.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	//Step 1 of instructions
	Resistor res_1 = Resistor(0.03); //create a resistor of 0.03 ohms
	cout << "Res_1: " << res_1.getResistance() << " ohms\n\n" << endl; //tell me the resistance and skip a few lines


	//step 2 of instructions
	VoltageSupply vs_1 = VoltageSupply(10); //create a 10v supply
	cout << "VS_1: " << vs_1.getVoltage() << " volts" << endl; //display how many volts it has
	double new_voltage = 0; //init a variable to let user set the new voltage
	cout << "Please enter a new value for voltage: ";
	cin >> new_voltage; //takes input
	vs_1.setVoltage(new_voltage); //sets voltage = new_voltage
	cout << "\n***updating***\n" << "VS_1: " << vs_1.getVoltage() << " volts\n\n" << endl; //outputs new voltage and skips a few lines

	//step 3
	Diode d_1 = Diode();
	//Note: Output members of diode here??
	Diode d_2 = Diode((2.0 * pow(10, -14)), (2 * pow(10, -2)));
	//output values?
	Diode d_3 = Diode((2.9 * pow(10, -16)), (2.9 * pow(10, -4)), 1.436);
	//output values?

	//step 4
	Circuit circ_1 = Circuit(); //creates default Circuit circ_1
	cout << "\n\nCircuit 1:\nResistance: " << (circ_1.getResistor()).getResistance() << " ohms\n\nVoltage Supplied: " << (circ_1.getVoltageSupply()).getVoltage() << " volts\n\nDiode satCurrent: " << (circ_1.getDiode()).getSatCurrent() << " amperes\n\nDiode thermalVoltage: " << (circ_1.getDiode()).getThermalVoltage() << " volts\n\nDiode Ideality: " << (circ_1.getDiode()).getIdeality() << endl;

	new_voltage = 0; //resets new voltage so I can use it again...
	

	//step 5: somehow use a pointer to make a new circuit!
	Circuit circ_2 = Circuit( (circ_1.getVoltageSupply()), (circ_1.getResistor()), (circ_1.getDiode()) );
	cout << "\n\nCircuit 2:\nResistance: " << (circ_2.getResistor()).getResistance() << " ohms\n\nVoltage Supplied: " << (circ_2.getVoltageSupply()).getVoltage() << " volts\n\nDiode satCurrent: " << (circ_2.getDiode()).getSatCurrent() << " amperes\n\nDiode thermalVoltage: " << (circ_2.getDiode()).getThermalVoltage() << " volts\n\nDiode Ideality: " << (circ_2.getDiode()).getIdeality() << endl;

	//compute Vd HERE and output it. Maybe a separate recursive function a la Project 1?
	cout << "\n\nV_d of the circuit is: " << newt_raph(circ_2, 0.6) << " volts" << endl;

	//Set the members of circ_2 equal to the parts I already created because I don't want to type out pow( 10, blah blah) any more
	circ_2.setVoltageSupply(vs_1);
	circ_2.setResistor(res_1);
	circ_2.setDiode(d_3);

	cout << "Circuit 2 has been rebuilt with different components! Now:";
	cout << "\n\nResistance: " << (circ_2.getResistor()).getResistance() << " ohms\n\nVoltage Supplied: " << (circ_2.getVoltageSupply()).getVoltage() << " volts\n\nDiode satCurrent: " << (circ_2.getDiode()).getSatCurrent() << " amperes\n\nDiode thermalVoltage: " << (circ_2.getDiode()).getThermalVoltage() << " volts\n\nDiode Ideality: " << (circ_2.getDiode()).getIdeality() << endl;

	//compute Vd HERE and output it. Maybe a separate recursive function a la Project 1?
	cout << "\n\nV_d of the circuit is: " << newt_raph(circ_2, 0.6) << " volts" << endl;

    return 0;
}

