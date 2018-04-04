#pragma once
//Author: August Koehler
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Matrix
{
	
	//Input the array values
	friend istream &operator>>(istream &input, const Matrix &obj);

	//Outputs to terminal a pretty little matrix
	friend ostream &operator<<(ostream &output, const Matrix &obj);

	
	

private:
	int rows;
	int cols;
	double** data;


public:
	//Normal constructor
	Matrix(int, int);

	/*Copy constructor
		obj_a is passed object
	*/
	Matrix(const Matrix & obj_a);

	//deconstructor!!
	~Matrix();

	//Copy operator assignment
	const Matrix &operator=(const Matrix& obj_b);


	//Adds the two matrices
	Matrix &operator+(const Matrix& obj_b);

	//subtracts the two matrices
	Matrix &operator-(const Matrix& obj_b);

	//Adds obj_b to THIS matrix
	Matrix &operator+=(const Matrix& obj_b);

	//subtracts obj_b from THIS matrix
	Matrix &operator-=(const Matrix& obj_b);


	//Matrix multiplication
	Matrix &operator*(const Matrix& obj_b);

	//preincrement
	Matrix &operator++();

	//postincrement
	Matrix &operator++(int);

	//predecrement
	Matrix &operator--();
	//postdecrement
	Matrix &operator--(int);

	//asserts whether the matrices have same size
	bool assert_dimensions(const Matrix&);
	//asserts proper dimensions for multiplication!
	bool assert_mult(const Matrix&);

	//The following function was suggested to me by my friend in CS who knows more of the arcana and suchforth of the c++ than I do.
	//They are used in the overloaded >> operator declaration.

	//self explanatory
	double** getData() const;

};


void test_all(const Matrix&, const Matrix&);

