#include "stdafx.h"
#include "Resistor.h"

//constructor
Resistor::Resistor(double r) : resistance(r) 
{
}
//resistance getter: returns resistance
double Resistor::getResistance()
{
	return resistance;
}
//sets resistance = to double arg
void Resistor::setResistance(double r)
{
	resistance = r;
}

