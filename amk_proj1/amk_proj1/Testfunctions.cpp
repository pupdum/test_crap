/*This is the file containing testfunction definitions as prototyped in Testfunctions.h*/

#include "Testfunctions.h"
#include <iostream>
#include <cmath>
#include "stdafx.h"

using namespace std;

//Definition of f1
double f1(double a) {
	return a * a - 5 * a + 6;
}
//Def of f1 first derivative
double f1_prime(double b) {
	return 2 * b - 5;
}
//Def of f1 second derivative
double f1_dprime(double e) {
	return 2;
}

//Def of f2
double f2(double c) {
	return cos(2 * c);
}
//Def of f2 derivative
double f2_prime(double d) {
	return -2 * sin(2 * d);
}
//Def of f2 second derivative
double f2_dprime(double f) {
	return -4 * cos(2 * f);
}