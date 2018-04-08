#include "stdafx.h"
#include "Diode.h"
#include <cmath>


//default constructor, sets defaults to given values
Diode::Diode() : satCurrent(2.6 * pow(10, -15)) , thermalVoltage(26 * pow(10, -3)), ideality(1)
{
}

//constructor takes satcurrent and thermalvoltage as args, uses default ideality
Diode::Diode(double sC, double tV) : satCurrent(sC), thermalVoltage(tV), ideality(1)
{
}

//takes all members as args...
Diode::Diode(double sC, double tV, double i) : satCurrent(sC), thermalVoltage(tV), ideality(i)
{
}

//SC getter
double Diode::getSatCurrent()
{
	return satCurrent;
}
//SC setter
void Diode::setSatCurrent(double sC)
{
	satCurrent = sC;
}

//TV getter
double Diode::getThermalVoltage()
{
	return thermalVoltage;
}
//TV setter
void Diode::setThermalVoltage(double tV)
{
	thermalVoltage = tV;
}

//ideality getter
double Diode::getIdeality()
{
	return ideality;
}
//ideality setter
void Diode::setIdeality(double i)
{
	ideality = i;
}