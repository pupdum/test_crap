#pragma once
class Resistor
{
public:
	Resistor(double); //Constructor, sets resistance = to double arg

	double getResistance(); //returns resistance

	void setResistance(double); //sets resistance to double arg

private:
	double resistance; //the resistance of the resistor determined by all sorts of properties waayy outside the scope of this assignment
	
};

