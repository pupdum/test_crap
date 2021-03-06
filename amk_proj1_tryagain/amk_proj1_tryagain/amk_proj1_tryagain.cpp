// amk_proj1.cpp : Defines the entry point for the console application.
//
/*
Author: August Koehler
Date: 2/16/18
Description: Main file for this project, controls everything else.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Testfunctions.h"
#include "Halley.h"


using namespace std;

int main()
{
	int keep_going = 1;
	double g1, g2;
	while (keep_going) {
		cout << "Please enter a guess for the root of function F(x) = x^2 -5x + 6 : ";
		cin >> g1;
		cout << "\n\nPlease enter a guess for the root of function F(x) = cos( 2x ) : ";
		cin >> g2;

		cout << "\n" << HalleyRecursiveA(g1);
	}
	return 0;
}
