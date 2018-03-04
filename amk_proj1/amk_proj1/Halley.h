#pragma once

/*Contains function prototypes for Halley's method functions as defined in Halley.cpp
Author: August Koehler
*/

//Group of recursive Halley prototypes

double HalleyRecursiveA(double guess);
double HalleyRecursiveB(double guess);
//double HalleyRecursiveC(double guess);

//Group of iterative Halley prototypes

double HalleyIterativeA(double guess);
double HalleyIterativeB(double guess);
//double HalleyIterativeC(double guess);

//These functions are modified versions of those above to make it easier to return a table of this stuff...

std::vector<double> hRA(double guess);
double HRB(double guess);

double HIA(double guess);
double HIB(double guess);