// testgrader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;


int main()
{
	char grade;
	cout << "Input grade" << endl;
	cin >> grade;
	

	switch (grade) {
	case 'A':
	case 'a'://grade A
		cout << "You got an A!" << endl;
		break;
	case 'B':
	case 'b'://grade B
		cout << "You got an B!" << endl;
		break;
	case 'C':
	case 'c':// grade C
		cout << "You got an C!" << endl;
		break;
	case 'D':
	case 'd':// grade D
		cout << "You got an D!" << endl;
		break;

	default:
		cout << "You failed motherfucker, you failed!" << endl;
	}
    return 0;
}

