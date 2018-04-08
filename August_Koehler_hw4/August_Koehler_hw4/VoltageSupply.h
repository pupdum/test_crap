#pragma once
class VoltageSupply
{
public:
	VoltageSupply(double); //Constructor, sets member voltage = to arg double
	

	double getVoltage(); //Returns voltage
	void setVoltage(double); //sets voltage to double

private:
	double voltage; //the voltage supplied by this VS...
};

