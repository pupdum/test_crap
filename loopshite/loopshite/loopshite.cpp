// loopshite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	cout << "Let's play 'Guess my number!' Please enter an int between 10 and 20." << endl;
	int guess;
	while (guess != 17) {
		cin >> guess;
		if (guess >= 10 && guess <= 20) {
			cout << "Sorry, not the right one!" << endl;
		} 
	}
    return 0;
}

