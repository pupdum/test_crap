/*Definitions for Halley functions as prototyped in Halley.h
Author: August Koehler
*/

#include "Halley.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "stdafx.h"
#include "Testfunctions.h"

//Group of recursive Halley functions

double HalleyRecursiveA(double guess) {
	double suffering = ((2 * f1(guess)* f1_prime(guess)) / (2 * (pow(f1_prime(guess), 2) - f1(guess)* f1_dprime(guess)))); //The term that gets subtracted, separated to make code more legible
	double x_n = guess - suffering; //Subtract that stuff from initial value

	if (suffering > 0.0001) {
		return HalleyRecursiveA(x_n); //ideally causes recursion, stopping when the change is less than the specified amount
	}
	else {
		return x_n;
	}
}

double HalleyRecursiveB(double guess) {
	double pain = ((2 * f2(guess)* f2_prime(guess)) / (2 * (pow(f2_prime(guess), 2) - f2(guess)* f2_dprime(guess)))); //Same as above except uses the second function
	double x_n = guess - pain;

	if (pain > 0.0001) {
		return HalleyRecursiveA(x_n);
	}
	else {
		return x_n;
	}
}


//double HalleyRecursiveC(double guess) {



//Group of iterative Halley functions

double HalleyIterativeA(double guess) {
	double temp_var = guess; //This makes it easier to change the value for the next step
	for (int i = 0; i < 100; i++) {
		double foo = ((2 * f1(temp_var)* f1_prime(temp_var)) / (2 * (pow(f1_prime(temp_var), 2) - f1(temp_var)* f1_dprime(temp_var)))); //evaluates expression

		if (foo > 0.0001) {
			temp_var -= foo; //When change is >0.0001 it will keep going
		}
		else {
			return temp_var; //when change is < 0.0001 it will return the last result and exit.
			break;
		}
	}
}

double HalleyIterativeB(double guess) {
	double temp_var = guess; //This makes it easier to change the value for the next step
	for (int i = 0; i < 100; i++) {
		double foo = ((2 * f2(temp_var)* f2_prime(temp_var)) / (2 * (pow(f2_prime(temp_var), 2) - f2(temp_var)* f2_dprime(temp_var)))); //evaluates expression
		if (foo > 0.0001) {
			temp_var -= foo; //When change is >0.0001 it will keep going
		}
		else {
			return temp_var; //when change is < 0.0001 it will return the last result and exit.
			break;
		}
	}
}

//double HalleyIterativeC(double guess) {


//Here are modified versions that are used for making the tables...
static std::vector<double> heck(1);
static std::vector<double> circle_1;
static std::vector<double> circle_2;

std::vector<double>* hRA(double guess) {
	static int evil = 0;
	circle_2.resize(1, 0);
	double suffering = ((2 * f1(guess)* f1_prime(guess)) / (2 * (pow(f1_prime(guess), 2) - f1(guess)* f1_dprime(guess)))); //The term that gets subtracted, separated to make code more legible
	double x_n = guess - suffering; //Subtract that stuff from initial value
	
	if (( suffering >= 0.0001) || ( suffering <= -0.0001)) {
		while (evil < 100) {
			if (evil == 0) {
				heck.at(evil) = x_n;
				evil++;
				return hRA(x_n);
			}
			else {
				heck.push_back(x_n);
				evil++;
				return hRA(x_n);
			}
		}
	}
	else {
		evil = 0;
		circle_1 = heck;
		heck.resize(1, 0);
		return &circle_1;
	}
}

std::vector<double>* hRB(double guess) {
	static int fear = 0;
	circle_1.resize(1, 0);
	double temp_var = guess; //This makes it easier to change the value for the next step
	double foo = ((2 * f2(temp_var)* f2_prime(temp_var)) / (2 * (pow(f2_prime(temp_var), 2) - f2(temp_var)* f2_dprime(temp_var))));
	if ((foo >= 0.0001) || (foo <= -0.0001)) {
		while (fear < 100) {
			if (fear == 0) {
				heck.at(fear) = foo;
				fear++;
				return hRB(foo);
			}
			else if (foo <= .05 && foo >= -.05) {
				heck.push_back(0);
				circle_2 = heck;
				fear = 0;
				heck.resize(1, 0);
				return &circle_2;
			}
			else {
				heck.push_back(foo);
				fear++;
				return hRB(foo);
			}
		}
	}
	else {
		circle_2 = heck;
		fear = 0;
		heck.resize(1, 0);
		return &circle_2;
	}
}


double HIA(double guess) {
	double temp_var = guess; //This makes it easier to change the value for the next step
	double foo = ((2 * f1(temp_var)* f1_prime(temp_var)) / (2 * (pow(f1_prime(temp_var), 2) - f1(temp_var)* f1_dprime(temp_var)))); //evaluates expression
	return guess - foo;
}

double HIB(double guess) {
	double pain = ((2 * f2(guess)* f2_prime(guess)) / (2 * (pow(f2_prime(guess), 2) - f2(guess)* f2_dprime(guess)))); //Same as above except uses the second function
	double x_n = guess - pain;
	return x_n;
}


