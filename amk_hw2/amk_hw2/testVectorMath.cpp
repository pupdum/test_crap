// amk_hw2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "VectorMath.h"

using namespace std;

int main()
{
	int going = 1;
	int no_comp, selector;
	char gniog;
	double v1[3] = { 0, 0, 0 };
	double v2[3] = { 0, 0, 0 };
	vector<double> r1(3, 0);
	vector<double> r2(3, 0);
	vector<double> ov(3, 0);
	double *o;

	while (going) {
		cout << "Enter number of Vector Components: ";
		cin >> no_comp;

		if (no_comp > 3 || no_comp < 1) {
			cout << "Invalid number of components, please try again with 1 <= n <= 3 \n\n";
			continue;
		}

		cout << "\nOperations Available: \n(0) Addition \n(1) Subtraction \n(2) Magnitude \n(3) Dot Product \n(4) Cross Product" << "\n\nPlease Select an Operation: ";
		cin >> selector;

		
		cout << "Enter Component Values of Vector 1" << endl;
		if (no_comp == 1) { //assigns the value of the first index for the first vector/array
				cout << "i: ";
				cin >> v1[0];
				r1[0] = v1[0];
		} 
		else if (no_comp == 2) { //assigns values of first two indices for 2 component array/vect
				cout << "i: ";
				cin >> v1[0];
				r1[0] = v1[0];
				cout << "j:";
				cin >> v1[1];
				r1[1] = v1[1];
		} 
		else { // assigns all 3 indices for the first array/vecto
				cout << "i: ";
				cin >> v1[0];
				r1[0] = v1[0];
				cout << "j: ";
				cin >> v1[1];
				r1[1] = v1[1];
				cout << "k: ";
				cin >> v1[2];
				r1[2] = v1[2];
		}

		if (selector != 2) { //index 1 of v2, r2
			cout << "\nEnter Component Values of Vector 2" << endl;
			if (no_comp == 1) {
				cout << "i: ";
				cin >> v2[0];
				r2[0] = v2[0];
			}
			else if (no_comp == 2) { //first 2 indices for r2, v2
				cout << "i: ";
				cin >> v2[0];
				r2[0] = v2[0];
				cout << "j:";
				cin >> v2[1];
				r2[1] = v2[1];
			}
			else { // 3 comp array/vector assignments
				cout << "i: ";
				cin >> v2[0];
				r2[0] = v2[0];
				cout << "j: ";
				cin >> v2[1];
				r2[1] = v2[1];
				cout << "k: ";
				cin >> v2[2];
				r2[2] = v2[2];
			}
		}
		

		switch (selector) {
		case 0: 
			
			o = addArray(v1, v2, no_comp);
			ov = addVector(r1, r2);
			
			cout << "\nArray Result: \n\ni: " << *o << "\nj: " << *(o+1) << "\nk: " << *(o+2) << endl;

			cout << "\nVector Result: \n\ni: " << ov[0] << "\nj: " << ov[1] << "\nk: " << ov[2] << endl;
			break; //select and executes addition function

		case 1:
			
			o = subArray(v1, v2, no_comp);
			ov = subVector(r1, r2);

			cout << "\nArray Result: \n\ni: " << *o << "\nj: " << *(o + 1) << "\nk: " << *(o + 2) << endl;

			cout << "\nVector Result: \n\ni: " << ov[0] << "\nj: " << ov[1] << "\nk: " << ov[2] << endl;
			break; //selects and executes subtraction


		case 2:
			cout << "\nArray Result: \n" << magArray(v1, no_comp) << endl;
			cout << "\nVector Result: \n" << magVector(r1) << endl;

			break; // Magnitude


		case 3: 
			cout << "\nArray Result: \n" << dotArray(v1, v2, no_comp) << endl;
			cout << "\nVector Result: \n" << dotVector(r1, r2) << endl;

			break; // *Product


		case 4:
			o = xArray(v1, v2, no_comp);
			ov = xVector(r1, r2);

			cout << "\nArray Result: \n\ni: " << *o << "\nj: " << *(o + 1) << "\nk: " << *(o + 2) << endl;

			cout << "\nVector Result: \n\ni: " << ov[0] << "\nj: " << ov[1] << "\nk: " << ov[2] << endl;
			break; // X-Product!!
		default: cout << "\n\nInvalid operation, please enter 0, 1, 2, 3, or 4\n" << endl;
			continue; //restarts loop if given invalid inputs because I don't wanna make a mess.
		}

		//redeclares the arrays and vectors to resent to default of 0,0,0 so the math doesn't goof up if user uses smaller arrays/vectors
		double v1[3] = { 0, 0, 0 };
		double v2[3] = { 0, 0, 0 };
		vector<double> r1(3, 0);
		vector<double> r2(3, 0);
		vector<double> ov(3, 0);
		// end that stuff

		cout << "\n\nTry New (Y/N)? ";
		cin >> gniog;
		switch (gniog) {
		case 'y':
		case 'Y': 
			break; //if y or Y, will just exit switch and start loop over
		case 'n':
		case 'N': going = 0;
			break; //if n or N, will set the loop variable to be false, thusly quitting the program
		}
	}
	cout << "XXxx_Pr0gR4m__T3rMin4t3d" << endl;
    return 0;
}

