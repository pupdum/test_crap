/*Definitions for Halley functions as prototyped in Halley.h*/

#include "Halley.h"
#include <iostream>
#include <cmath>
#include "stdafx.h"
#include "Testfunctions.h"

//Group of recursive Halley functions

double HalleyRecursiveA(double guess) {
	double suffering = ((2 * f1(guess)* f1_prime(guess)) / (2 * (pow(f1_prime(guess), 2) - f1(guess)* f1_dprime(guess))));
	double x_n = guess - suffering;

	if (suffering > 0.0001) {
		return HalleyRecursiveA(x_n);
	}
	else {
		return x_n;
	}
}

double HalleyRecursiveB(double guess) {
	double pain = ((2 * f2(guess)* f2_prime(guess)) / (2 * (pow(f2_prime(guess), 2) - f2(guess)* f2_dprime(guess))));
	double x_n = guess - pain;

	if (pain > 0.0001) {
		return HalleyRecursiveA(x_n);
	}
	else {
		return x_n;
	}
}

//not sure what the recursiveC and iterativeC functions are for, considering I'll only need four functions to implement two versions of Halley's method I think.
//double HalleyRecursiveC(double guess) {



//Group of iterative Halley functions

double HalleyIterativeA(double guess) {

}

double HalleyIterativeB(double guess) {

}

//double HalleyIterativeC(double guess) {
