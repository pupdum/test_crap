/*  FileName:    sortingMain.cpp
*  Author:
*  Date:
*  Bein used by: August Koehler
*  Description:  Sort integers using selection and bubble sort
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include "Sorting.h"

using namespace std;
// Global Variable for main
// Stores the values read in from a tex file
static int* values;

int readInValues(char* fileName);
/**
* @param argc - number of command line arguments
* @param argv - arguments 
* @return - 0 for ok termination, -1 for error
*/
int main(int argc, char* argv[])
{
	if( argc != 2 ){
		cerr << "usage: " << argv[0] << " <filename>\n";
		return -1;
	}else{
	// Get filename from the command line arguments
		char *fileName = argv[1];
	
	// Read in the values
		int numValues = readInValues(fileName);
	
	// Store the algorithm and sorting choice
		int sortChoice;
		int orderChoice;
		
	// Get the algorithm choice
		cout << "--------------------" << endl;
		cout << "Enter Sorting Method" << endl;
		cout << "(0) Selection Sort\n";
		cout << "(1) Bubble Sort\n";
		cout << "Enter choice: ";
		cin >> sortChoice;
	// Get the comparison choice 
		cout << "--------------------" << endl;
		cout << "Enter Order" << endl;
		cout << "(0) Ascending\n";
		cout << "(1) Descending\n";
		cout << "Enter choice: ";
		cin >> orderChoice;
		cout << "--------------------" << endl;
// Based on user input call the appropriate functions
		switch(sortChoice)
		{
		case 0:
			if( orderChoice ){
				sortArray(values, numValues, selectionSort, descending);
			}else{
				sortArray(values, numValues, selectionSort, ascending);
			}
			break;
		case 1:
			if( orderChoice ){
				sortArray(values, numValues, bubbleSort, descending);
			}else{
				sortArray(values, numValues, bubbleSort, ascending);
			}
				break;
		}
// Print out the results
		cout << "--------------------" << endl;
		cout << "Results\n" << endl;
		// Print out the Values
		for(int i=0; i<numValues; i++){
		cout << *values <<endl;
		values++;
		}
		cout << "--------------------" << endl;
		}
	_getch();
return 0;
}
/**
* @arg fileName - filename to read in integer values from.
* 
* @return - the number of elements read
*/
int readInValues(char* fileName)
{
	int cValue; // Store the current value
	int numValues; // Store number of values
	
	// Open the text file
		ifstream infile(fileName);
		
	// Check to see if the file opened ok
		if (!infile) {
			cout << "There was a problem opening file " << fileName << " for reading.\n";
			return -1;
		}
		
	// Prompt
		cout << "Opened " << fileName << " for reading.\n";
		
	// Get the first value to signify the number of  values in the file
		infile >> numValues;
		
	// Allocate memory space
		values = (int*)malloc( numValues*sizeof(int) );
		
	// Read in the values, incrementing the pointer
		for(; infile >> cValue; values++){
		// Deference the current pointer location Store read in value 
			*values = cValue;   
		}
		
	// Reset the pointer to orginal location
		values-=numValues;
		
	// Prompt
		cout << "Finished Reading in values\n";
	// Return the number of values read
	return numValues;
}