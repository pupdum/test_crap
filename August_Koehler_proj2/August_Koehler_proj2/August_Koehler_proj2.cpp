// August_Koehler_proj2.cpp : Defines the entry point for the console application.
// Author: August Koehler

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

int main()
{
	int carry_on = 1;

	while (carry_on) {
		int a_rows = 0, a_cols = 0, b_rows = 0, b_cols = 0;

		cout << "\n\nPlease enter the # of rows and # of columns of your first matrix: ";
		cin >> a_rows >> a_cols;

		cout << "\n\nPlease enter the # of rows and # of columns of your second matrix: ";
		cin >> b_rows >> b_cols;

		Matrix a = Matrix(a_rows, a_cols);

		Matrix b = Matrix(b_rows, b_cols);

		cout << "\n\nPlease enter the values in matrix a by separating elements in a row by a space and using a newline (enter key) to go to the next row \n" << endl;
		cin >> a;

		cout << "\n\nPlease enter the values in matrix b by separating elements in a row by a space and using a newline (enter key) to go to the next row \n" << endl;
		cin >> b;


		//this following bundle of snakes lets the user decide what kind of operation they want to do and does it.
		int op_sel;
		cout << "\nWould you like to: \n + + + + + + \n  1: a + b \n  2: a += b \n\n - - - - - - \n  3: a - b \n"
			<< "  4: a -= b \n  5: b - a \n  6: b -= a \n\n * * * * * *  \n  7: a * b \n  8: b * a \n\n"
			<< "+1 +1 +1 +1 +1 +1 \n  9: ++a \n 10: a++ \n 11: ++b \n 12: b++ \n\n -1 -1 -1 -1 -1 -1 \n"
			<< " 13: --a \n 14: a-- \n 15: --b \n 16: b-- \n\n\n 20: Do ALL operations (debug feature - do not use unless both matrices are same size)" << endl;
		cout << "______ ________ _______ ________\n\n" << "Your choice: ";
		cin >> op_sel;

		switch (op_sel) {
		case 20:	//function not yet written tbh
			test_all(a, b);
			break;

		case 1: //additions
			cout << "\n\n"<< (a + b);
			break;

		case 2:
			a += b;
			cout << "\n\n" << a;
			break;

		case 3: //subtractions
			cout << "\n\n" << (a - b);
			break;

		case 4:
			a -= b;
			cout << "\n\n" << a;
			break;

		case 5:
			cout << "\n\n" << (b - a);
			break;

		case 6:
			b -= a;
			cout << "\n\n" << b;
			break;

		case 7: //multiplications!
			cout << "\n\n" << (a * b);
			break;

		case 8:
			cout << "\n\n" << (b * a);
			break;

		case 9: //preincr
			cout << "\n\n" << ++a;
			break;
			
		case 10: //postincr
			cout << "\n\n" << a++;
			break;

		case 11: //preinc
			cout << "\n\n" << ++b;
			break;

		case 12: //postinc
			cout << "\n\n" << b++;
			break;

		case 13: //predec
			cout << "\n\n" << --a;
			break;

		case 14: //postdec
			cout << "\n\n" << a--;
			break;

		case 15:
			cout << "\n\n" << --b;
			break;

		case 16:
			cout << "\n\n" << b--;
			break;

		default:
			cout << "invalid input, please start again...";
				break;
		}




		//this block exits the loop and thus exits the program if correct input char not given.
		char kill_this;
		cout << "\n\n\nIf you would like to restart enter y. Otherwise, to exit, enter anything else...  ";
		cin >> kill_this;

		switch (kill_this) {
		case 'y':	break; //restarts loop.

		default:
			carry_on = 0; //kills loop and program.
			continue;
		}

	}
	
	return 0;
}

