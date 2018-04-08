#include "stdafx.h"
#include "Circuit.h"

//default constructor, creates default diode, 1k resistor, and a 2v supply
Circuit::Circuit() : diode(Diode()), resistor(Resistor(1000)), voltageSupply(VoltageSupply(2.0))
{
}

//Constructor; takes objects of the three types as arguments and sets members to be those objects
// Might have to change this to take const (class)& pointer thingies to work right.
Circuit::Circuit(VoltageSupply& v_sup, Resistor& res, Diode& dio) : voltageSupply(v_sup), resistor(res), diode(dio)
{
}


//returns member object voltage supply
VoltageSupply Circuit::getVoltageSupply()
{
	return voltageSupply;
}

//sets member voltageSupply to be the one inputted from the argument
void Circuit::setVoltageSupply(VoltageSupply v_sup)
{
	voltageSupply = v_sup;
}

//returns member resistor
Resistor Circuit::getResistor()
{
	return resistor;
}
//sets member resistor to be argument object
void Circuit::setResistor(Resistor r)
{
	resistor = r;
}

//returns member object diode
Diode Circuit::getDiode()
{
	return diode;
}
//sets member diode to be arg object Diode
void Circuit::setDiode(Diode dio)
{
	diode = dio;
}


//returns value of Shockley eq in this circuit.
double Circuit::shockley(double guess)
{
	double iv = ((this->getVoltageSupply()).getVoltage() - guess) / (this->getResistor()).getResistance() - (this->getDiode()).getSatCurrent() * (exp(guess / ((this->getDiode()).getIdeality() * (this->getDiode()).getThermalVoltage())));
	return iv;
}
//returns value of first derivative of Shockley eq in this circuit.
double Circuit::shockley_prime(double guess)
{
	double ivp = (-1 / (this->getResistor()).getResistance() ) - ((this->getDiode()).getSatCurrent() / (((this->getDiode()).getIdeality()) * (this->getDiode()).getThermalVoltage())) * exp(guess / ((this->getDiode()).getIdeality() * (this->getDiode()).getThermalVoltage()));
	return ivp;
}



//solves for V_d using argument Circuit circuit and value guess
double newt_raph(Circuit& circ, double guess)
{
	double temp_var = guess; 
	for (int i = 0; i < 100; i++) {
		double foo = temp_var - (circ.shockley(guess) / (circ.shockley_prime(guess)));
		if (foo > 0.0001) {
			temp_var -= foo; //When change is >0.0001 it will keep going
		}
		else {
			return temp_var; //when change is < 0.0001 it will return the last result and exit.
			break;
		}
	}
}

