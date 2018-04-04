#include "stdafx.h"
#include "Matrix.h"

//Author: August Koehler

Matrix::Matrix(int a, int b) : rows(a), cols(b) 
{
	 data = new double*[a]; //This code shamefully taken from stack overflow because I am not exactly sure how to do crazy dynamic allocation like this
	 data[0] = new double[a * b]; //makes the first index of data a ptr to the height * width I'm not exactly sure
	 for (int i = 1; i < a; i++)
		 data[i] = data[i - 1] + b; //does a heckin sorcery

	 //https://stackoverflow.com/a/29375830  -- Ben Voigt 

	 //now to initialize the matrix!

	 for (int x = 0; x < rows; x++) {
		 for (int y = 0; y < cols; y++)
			 data[x][y] = 0;
	 }
}

Matrix::~Matrix()
{
	delete[] data[0];
	delete[] data;
}

Matrix::Matrix(const Matrix & obj_a) {
	this->rows = obj_a.rows;
	this->cols = obj_a.cols;

	this->data = new double*[this->rows]; //This code shamefully taken from stack overflow because I am not exactly sure how to do crazy dynamic allocation like this
	this->data[0] = new double[this->rows * this->cols]; //makes the first index of data a ptr to the height * width I'm not exactly sure
	for (int i = 1; i < this->rows; i++)
		this->data[i] = this->data[i - 1] + this->cols; //does a heckin sorcery

	//Initialize the matrix to the copied values what heck

	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->cols; y++)
			this->data[x][y] = obj_a.data[x][y];
	}
}

istream & operator>>(istream & input, const Matrix &obj)
{
	for (int x = 0; x < obj.rows; x++) {
		for (int y = 0; y < obj.cols; y++) {
			input >> obj.getData()[x][y];
		}
	}
	
	return input;
}

ostream & operator<<(ostream & output, const Matrix & obj)
{
	for (int x = 0; x < obj.rows; x++) {
		for (int y = 0; y < obj.cols; y++) {
			output << std::setw(10) << obj.data[x][y];
		}
		output << endl;
	}
	return output;
}

//Copy operator - sets the thing equal to the other thing
const Matrix & Matrix::operator=(const Matrix & obj_b)//current issues - won't return a value
{	
	if (this == &obj_b)
		return *this;

	if ((this->rows != obj_b.rows) || (this->cols != obj_b.cols)) { //if they aren't same size, re-allocate the durned matrix
		delete[] this->data[0];
		delete[] this->data;

		this->rows = obj_b.rows;
		this->cols = obj_b.cols;
		//creates a new thingy for this->data
		this->data = new double*[this->rows]; //This code shamefully taken from stack overflow because I am not exactly sure how to do crazy dynamic allocation like this
		this->data[0] = new double[this->rows * this->cols]; //makes the first index of data a ptr to the height * width I'm not exactly sure
		for (int i = 1; i < this->rows; i++)
			this->data[i] = this->data[i - 1] + this->cols; //does a heckin sorcery
	}

	//initializes the new data to be the same as obj_b
	for (int x = 0; x < obj_b.rows; x++) {
		for (int y = 0; y < obj_b.cols; y++)
			this->data[x][y] = obj_b.data[x][y];   // it is going crazy here!
	}
	
	return *this;
}


Matrix & Matrix::operator+(const Matrix & obj_b)
{
	Matrix temp_mat = *this;
	char dims_error[] = "Operand matrices do not have correct dimensions for operation to succeed. Please try again with equal dimensions. Thank you.";
	if (this->assert_dimensions(obj_b)) {

		for (int x = 0; x < this->rows; x++) {
			for (int y = 0; y < this->cols; y++)
				temp_mat.data[x][y] += obj_b.data[x][y];
		}
		*this = temp_mat;
		return *this;
	}
	else {
		std::cerr << "Error: " << dims_error << endl;
		exit(1);
	}
}

Matrix & Matrix::operator-(const Matrix & obj_b)
{
	Matrix temp_mat = *this;
	char dims_error[] = "Operand matrices do not have correct dimensions for operation to succeed. Please try again with equal dimensions. Thank you.";

	if (this->assert_dimensions(obj_b)) {

		for (int x = 0; x < this->rows; x++) {
			for (int y = 0; y < this->cols; y++)
				temp_mat.data[x][y] -= obj_b.data[x][y];
		}
		*this = temp_mat;
		return *this;
	}
	else {
		std::cerr << "Error: " << dims_error << endl;
		exit(1);
	}
}

Matrix & Matrix::operator+=(const Matrix & obj_b)
{

	char dims_error[] = "Operand matrices do not have correct dimensions for operation to succeed. Please try again with equal dimensions. Thank you.";
	if (this->assert_dimensions(obj_b)) {
		Matrix temp_mat = *this;

		for (int x = 0; x < this->rows; x++) {
			for (int y = 0; y < this->cols; y++)
				temp_mat.data[x][y] += obj_b.data[x][y];
		}
		*this = temp_mat;
		return *this;
	}
	else {
		std::cerr << "Error: " << dims_error << endl;
		exit(1);
	}
}

Matrix & Matrix::operator-=(const Matrix & obj_b)
{
	char dims_error[] = "Operand matrices do not have correct dimensions for operation to succeed. Please try again with equal dimensions. Thank you.";
	if (this->assert_dimensions(obj_b)) {

		for (int x = 0; x < this->rows; x++) {
			for (int y = 0; y < this->cols; y++)
				this->data[x][y] -= obj_b.data[x][y];
		}
		return *this;
	}
	else {
		std::cerr << "Error: " << dims_error << endl;
		exit(1);
	}
}

Matrix & Matrix::operator*(const Matrix &obj_b)
{
	double temp_var = 0;
	bool what = 0;
	what = this->assert_mult(obj_b);
	if ( what ) {
		Matrix result_mat(this->rows, obj_b.cols);

		for (int x = 0; x < this->rows; x++) { //fills in the resultant matrix
			for (int y = 0; y < obj_b.cols; y++) { //controls the filling of columns of the resultant matrix
				temp_var = 0;

				for (int i = 0; i < this->cols; i++) { //controls calculation of the dot product, uses the condition that A.cols == B.rows to match element indices and the two bigger loops to control which rows/columns are read through.
					temp_var += (this->data[x][i] * obj_b.data[i][y]);
				}
				result_mat.data[x][y] = temp_var; // sets the result at [x][y] to be the dot product calculated above.
			}
		}

		*this = result_mat;
		return *this;
	}
	else {
		char mult_error[] = "Operand matrices do not have correct dimensions for operation to succeed. Please try again with A.cols == B.rows. Thank you.";
		std::cerr << "Error: " << mult_error << endl;
		exit(1);
	}
}



//preincrement operator. Returns by reference and something about lvalue
Matrix & Matrix::operator++()
{
	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->cols; y++)
			this->data[x][y] += 1;
	}
	return *this;
}

//post increment. Returns by value - temp object with old value then returns copy of original. rvalue.
Matrix &Matrix::operator++(int)
{
	Matrix temp_mat = *this;
	
	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->cols; y++)
			temp_mat.data[x][y] += 1;
	}
	*this = temp_mat;
	return *this;
}

//predecrement
Matrix & Matrix::operator--()
{
	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->cols; y++)
			this->data[x][y] -= 1;
	}
	return *this;
}


//postdecrement
Matrix & Matrix::operator--(int)
{
	Matrix temp_mat = *this;

	for (int x = 0; x < this->rows; x++) {
		for (int y = 0; y < this->cols; y++)
			temp_mat.data[x][y] -= 1;
	}
	*this = temp_mat;
	return *this;
}

//asserts that both dimensions are identical for operations that require it
bool Matrix::assert_dimensions(const Matrix & other) {
	if (this->rows == other.rows && this->cols == other.cols)
		return 1;
	else
		return 0;

}

bool Matrix::assert_mult(const Matrix &other) {
	if (this->cols == other.rows) {
		return 1;
	}

	else
		return 0;
}

//a getter function even tho not really necessary...
double ** Matrix::getData() const
{
	return data;
}

//a function to test ALL possible operations for the given matrices!
void test_all(const Matrix &a, const Matrix &b)
{
	for (int i = 1; i <= 16; i++) {
		Matrix tmpa = Matrix(a);
		Matrix tmpb = Matrix(b);


		switch (i) {
		case 1: //additions
			cout << i << "\n\n" << (tmpa + tmpb);
			break;

		case 2:
			tmpa += tmpb;
			cout << i << "\n\n" << tmpa;
			break;

		case 3: //subtractions
			cout << i << "\n\n" << (tmpa - tmpb);
			break;

		case 4:
			tmpa -= tmpb;
			cout << i << "\n\n" << tmpa;
			break;

		case 5:
			cout << i << "\n\n" << (tmpb - tmpa);
			break;

		case 6:
			tmpb -= tmpa;
			cout << i << "\n\n" << tmpb;
			break;

		case 7: //multiplications!
			cout << i << "\n\n" << (tmpa * tmpb);
			break;

		case 8:
			cout << i << "\n\n" << (tmpb * tmpa);
			break;

		case 9: //preincr
			cout << i << "\n\n" << ++tmpa;
			break;

		case 10: //postincr
			cout << i << "\n\n" << tmpa++;
			break;

		case 11: //preinc
			cout << i << "\n\n" << ++tmpb;
			break;

		case 12: //postinc
			cout << i << "\n\n" << tmpb++;
			break;

		case 13: //predec
			cout << i << "\n\n" << --tmpa;
			break;

		case 14: //postdec
			cout << i << "\n\n" << tmpa--;
			break;

		case 15:
			cout << i << "\n\n" << --tmpb;
			break;

		case 16:
			cout << i << "\n\n" << tmpb--;
			break;

		default:
			cout << "invalid input, please start again...";
			break;
		}

		cout << "\n\n" << endl;
	}

}