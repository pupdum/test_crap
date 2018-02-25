#pragma once

//additions
double* addArray(double a[], double b[],  int);
std::vector<double> addVector(std::vector<double>, std::vector<double>);

//subtractions
double* subArray(double a[], double b[],  int);
std::vector<double> subVector(std::vector<double>, std::vector<double>);

//magnitude - returns scalar
double magArray(double[],  int );
double magVector(std::vector<double>);

//dot prod - returns scalar
double dotArray(double a[], double b[],  int);
double dotVector(std::vector<double>, std::vector<double>);

//xprod
double* xArray(double a[], double b[],  int);
std::vector<double> xVector(std::vector<double>, std::vector<double>);
