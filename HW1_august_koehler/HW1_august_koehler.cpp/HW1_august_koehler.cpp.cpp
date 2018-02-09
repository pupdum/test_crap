// HW1_august_koehler.cpp.cpp : Defines the entry point for the console application.
//

//I used my code from last semester when I did the exact same assignment in computational problem causing. This time I might be able to figure out the answer to the question because I have more time to fiddle with the code. I'm pretty happy that my code works verbatim although it would be nice to figure out how to do the fancy formatted output for the c++ specific i/o statements.
#include "stdafx.h"
#include <iostream>
#include <iomanip>

#define TRUE 1
#define FALSE 0

using namespace std;

void table_print(int r[], int size);
void separatist(long int n);
int are_diff(int r[], int size);
int are_div(int r[], int size, long int n);



int main()
{
	long int input;
	cout << "Enter a positive integer or 0 (zero) to end: ";
	cin >> input;
	while (input != 0) {
		if (input < 0) {
			cout << "Wrong input";
		}
		else {
			separatist(input);
		}
		cout << "\n\nEnter a positive integer or 0 (zero) to end: ";
		cin >> input;
	}
	cout << "*** Program Terminated ***\n";

    return 0;
}

void separatist(long int n) {
	int a[10] = { 0 }, digit;
	long int num = n;
	while (num > 0) {
		digit = num % 10;
		++a[digit];
		num /= 10;
	}
	table_print(a, 10);
	if (a[0] != 0) {
		cout << "Wrong input for the second part.\nInput should not contain zero.\n";
	}
	else if (are_diff(a, 10) == FALSE) {
		cout << "Wrong input for the second part.\nInput should not contain each digit more than once.\n";
	}
	else if (are_div(a, 10, n) == FALSE) {
		cout << n << " is not divisible by its digits.\n";
	}
	else {
		cout << n << "%ld is divisible by its digits";
	}
	
}

void table_print(int r[], int size) {
	cout << "\n\n";
	cout << "Digits:         0  1  2  3  4  5  6  7  8  9\nOccurances:   ";
	int i;
	for (i = 0; i< size; i++) {
		cout << "  " << r[i];
	}
	cout << "\n";
}

int are_diff(int r[], int size) {
	int i;
	for (i = 0; i<size; i++) {
		if (r[i] > 1) {
			return FALSE;
		}
	}
	return TRUE;
}

int are_div(int r[], int size, long int n) {
	int i;
	for (i = 0; i<size; i++) {
		if (r[i] == 0) {
			continue;
		}
		else if (n % i != 0) {
			return FALSE;
		}
	}
	return TRUE;
}