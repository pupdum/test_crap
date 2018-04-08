#include "stdafx.h"
#include "VoltageSupply.h"

//Constructor, sets member voltage = to arg double
VoltageSupply::VoltageSupply(double v) : voltage(v)
{
}

//Returns the voltage
double VoltageSupply::getVoltage()
{
	return voltage;
}
//Sets the voltage!
void VoltageSupply::setVoltage(double v)
{
	voltage = v;
}


