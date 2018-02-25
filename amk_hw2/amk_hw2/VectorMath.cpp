#include "stdafx.h"
#include <vector>
#include <cmath>


//these return double pointers to the first index. Will have to figure out the way to do the i/o later
double* addArray(double a[], double b[],  int length) { //addition with arrays
	double sum[] = { 0, 0, 0 }; //initialized to zero but max size. Will be returned
	for (int i = 0; i < length; i++) {
		sum[i] = a[i] + b[i];
	}
	return sum;
} 


std::vector<double> addVector(std::vector<double> a, std::vector<double> b) { //add with vectors
	std::vector<double> sumv(3, 0); 
	for (int i = 0; i < 3; i++) {
		sumv.at(i) = a[i] + b[i];
	}
	return sumv;
}

double* subArray(double a[], double b[],  int length) { //sub with arrays
	double diffa[] = { 0, 0, 0 };
	for (int i = 0; i < length; i++) {
		diffa[i] = a[i] - b[i];
	}
	return diffa;
}

std::vector<double> subVector(std::vector<double> a, std::vector<double> b) { //sub with vectors
	std::vector<double> diffv(3,0);
	for (int i = 0; i < 3; i++) {
		diffv.at(i) = a[i] - b[i];
	}
	return diffv;
}


//these four return scalar results therefore must return double.
double magArray(double a[], int length) { //returns a double of the magnitude scalar
	double mag = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	return mag;
}

double magVector(std::vector<double> a) { //returns double, magnitude scalar swag swag
	double magv = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	return magv;
}

double dotArray(double a[], double b[], int length) { //dot product with array
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


double dotVector(std::vector<double> a, std::vector<double> b) { //dot prod with vectors
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//last two return arrays so array pointer

double* xArray(double a[], double b[], int length) {
	double xpa[3] = { 0, 0, 0 };
	xpa[0] = a[1] * b[2] - a[2] * b[1];
	xpa[1] = a[2] * b[0] - a[0] * b[2];
	xpa[2] = a[0] * b[1] - a[1] * b[0];

	return xpa;
}


std::vector<double> xVector(std::vector<double> a, std::vector<double> b) {
	std::vector<double> xp(3,0);
	xp.at(0) = a[1] * b[2] - a[2] * b[1];
	xp.at(1) = a[2] * b[0] - a[0] * b[2];
	xp.at(2) = a[0] * b[1] - a[1] * b[0];

	return xp;
}