#pragma once

#include <cmath>

class Diode
{
public:
	Diode(); //default constructor, gives satCurrent = 2.6E-15, tVoltage = 26E-3, ideality = 1
	
	Diode(double sC, double tV); //constructor; takes double args as satCurrent and tVoltage, default ideality.

	Diode(double sC, double tV, double i); //constructor; takes same as above with inclusion of ideality factor as an argument.

	double getSatCurrent(); //sat current getter
	void setSatCurrent(double); //sat current setter

	double getThermalVoltage(); //thermal voltage getter
	void setThermalVoltage(double); //thermal voltage setter

	double getIdeality(); //ideality getter
	void setIdeality(double); //ideality setter


private:
	double satCurrent; // reverse bias saturation current I(naught) - a physical property of a diode :)
	double ideality; // factor between 1 and 2 that determines how well the diode behaves
	double thermalVoltage; //thermal voltage...
};

