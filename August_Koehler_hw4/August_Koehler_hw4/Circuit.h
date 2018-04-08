#pragma once
#include "Diode.h"
#include "Resistor.h"
#include "VoltageSupply.h"

class Circuit
{
public:
	Circuit(); //default constructor, sets R = 1000, VS = 2 V, sC = default, tV = default, ideality = default

	Circuit(VoltageSupply& , Resistor&,  Diode& ); //takes objects of VoltageSupply, Resistor, Diode to make a circuit.
	

	//returns the voltage supply in the circuit
	VoltageSupply getVoltageSupply();

	//sets the voltage supply in the circuit to argument of class VoltageSupply
	void setVoltageSupply(VoltageSupply);

	//returns the resistor in the circuit
	Resistor getResistor();

	//sets the resistor in the circuit to argument
	void setResistor(Resistor);

	//returns the diode in the circuit
	Diode getDiode();

	//sets the diode that is in the circuit to be the argument
	void setDiode(Diode);

	//Uses the definition of the Shockley Diode Eq and the values of the elements of this circuit to facilitate V_d calculation
	double shockley(double);
	//Uses the def of Shockley eq but returns the value of the first derivative of it for this circuit.
	double shockley_prime(double);


private:
	VoltageSupply voltageSupply; //object voltageSupply of class VoltageSupply
	Resistor resistor; // obkect resistor of class Resistor
	Diode diode; //object diode of class Diode
};


//solves for and returns the V_d!
double newt_raph(Circuit&, double guess); 


