// sillypositiveorneg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
int main()
{
	int dicks;
	cout << "Please enter a number" << endl;
	cin >> dicks;

	if (dicks > 0)
		cout << "input is positive";
	else if (dicks == 0) {
		cout << "input is zero";
	}
	else
		cout << "input is negative";
    return 0;
}

