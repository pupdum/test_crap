// anypower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int b, p, res = 1, i;
	cout << "Enter the base and power" << endl;
	cin >> b >> p;
	for (i = 1; i <= p; i++) {
		res *= b;
	}
	cout << res << endl;
    return 0;
}

