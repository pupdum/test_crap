// donutenter5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "enter any number but 5 please" << endl;
	int num = 0;
	while (num != 5) {
		cin >> num;
		cout << "enter any number but 5 please" << endl;
	}
	cout << "I told you not to enter 5!" << endl;

    return 0;
}

