/*Definitions for Halley functions as prototyped in Halley.h
Author: August Koehler
*/

#include "Halley.h"
#include <iostream>
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


//Here are modified versions that don't implement the recursion and iteration logic themselves, just returning the next approximation.


double HRA(double guess) {
	double suffering = ((2 * f1(guess)* f1_prime(guess)) / (2 * (pow(f1_prime(guess), 2) - f1(guess)* f1_dprime(guess)))); //The term that gets subtracted, separated to make code more legible
	double x_n = guess - suffering; //Subtract that stuff from initial value
	return x_n;
}

double HRB(double guess) {
	double pain = ((2 * f2(guess)* f2_prime(guess)) / (2 * (pow(f2_prime(guess), 2) - f2(guess)* f2_dprime(guess)))); //Same as above except uses the second function
	double x_n = guess - pain;
	return x_n;
}

double HIA(double guess) {
	double temp_var = guess; //This makes it easier to change the value for the next step
	double foo = ((2 * f1(temp_var)* f1_prime(temp_var)) / (2 * (pow(f1_prime(temp_var), 2) - f1(temp_var)* f1_dprime(temp_var)))); //evaluates expression
	return guess - foo;
}


double HIB(double guess) {
	double temp_var = guess; //This makes it easier to change the value for the next step
	double foo = ((2 * f2(temp_var)* f2_prime(temp_var)) / (2 * (pow(f2_prime(temp_var), 2) - f2(temp_var)* f2_dprime(temp_var))));
	return guess - foo;
}