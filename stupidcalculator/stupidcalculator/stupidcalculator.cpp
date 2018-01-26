// stupidcalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float powers(float a, float b);
int modulo(float a, float b);

int main()
{
	int going;
	going = 1;
	while (going == 1) {
		cout << "Please enter two numbers and one of the following operations: +, -, *, /, ^, %" << endl;
		char operation;
		float a, b;
		cin >> a >> b >> operation;
		switch (operation) {
		case '+':
			cout << "result:" << add(a, b) << endl;
			break;
		case '-':
			cout << "result:" << subtract(a, b) << endl;
			break;
		case '*':
			cout << "result:" << multiply(a, b) << endl;
			break;
		case '/':
			cout << "result:" << divide(a, b) << endl;
			break;
		case '^':
			cout << "result:" << powers(a, b) << endl;
			break;
		case '%':
			cout << "result:" << modulo(a, b) << endl;
			break;
		default:
			cout << "Please enter a valid operand next time" << endl;
			break;
		}
		cout << "Enter 1 to continue or 0 to quit" << endl;
		cin >> going;
	}

    return 0;
}

float add(float a, float b)
{
	return a + b;
}

float subtract(float a, float b)
{
	return a - b;
}

float multiply(float a, float b)
{
	return a * b;
}

float divide(float a, float b)
{
	return a / b;
}

float powers(float a, float b)
{
	return pow(a, b);
}

int modulo(float a, float b)
{
	return fmod(a,b);
}
