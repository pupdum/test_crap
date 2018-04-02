/*
*  FileName:    Sorting.cpp
*  Author:
*  Date:
*  Functions by: August Koehler
*  Description:  Implemented Functions for sorting. Bubble sort, Selection Sort
*/
#include "Sorting.h"
/**
*  This function sorts integers based on function pointers to 
*    a desired sorting function and desired comparison function.
*
*  @param values  - pointer to array of integers
*      @param n  - number of integers in the array
*  @param alg  - function pointer to sorting algorithm
*  @param cmp  - function pointer to comparision function
*
*/
//				  to sort    size      sorting algo choice                              order thingy
void sortArray(int* values, int n, void (*alg)(int*, int, bool (*cmp)(int,int)), bool (*cmp)(int,int) )
{
	int choice;
	if (*alg == bubbleSort) { choice = 0; }
	else { choice = 1; } //this bit translates the function pointers into a number so I could make my life easier when I ran into some trouble with the function pointer stuff.

	switch (choice) {
	case 0: bubbleSort(values, n, *cmp); //calls bubble sort with the passed arguments
		break;
	case 1: selectionSort(values, n, *cmp); //calls selection sort with the passed arguments
		break;
	}
// Finish
}
/**
*  This function sorts integers using the bubble sort method 
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void bubbleSort(int* values, int n, bool (*cmp)(int,int))
{
	int swapped = 0; //Gives an exit condition...
	do { // Palpatine voice *DO IT*
		swapped = 0;
		for (int i = 1; i <= n - 1; i++) {
			if (cmp(values[i - 1], values[i])) { //I'm assuming the ascending and descending functions will only differ in whether they return true or false to control when numbers get swapped.

				swap(&(values[i - 1]), &(values[i])); // shoobie doo wee doo swap, jazz!
				swapped = 1; // keeps it goin
			} //endif here
		} //endfor here
	} while (swapped);

// Finish
}
/**
*  This function sorts integers using the selection sort method 
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void selectionSort(int* values, int n, bool (*cmp)(int,int))
{
	int i, j, iMin; //lets make some ints

	for (j = 0; j < n - 1; j++) { //main loop controls all, provides multiple passes through
		iMin = j;
		for (i = j + 1; i < n; i++) {
			if (cmp(values[i], values[iMin]) != true) { //check here for possible logic error, might want to do "if not true" to get correct order - 3/24 had to put that negation in there to fix the order!
				iMin = i; //sets min/ max to new value depending on sort order.
			}
		}
		if (iMin != j) { //If there is a lower (or higher) number...
			swap(&(values[j]), &(values[iMin])); //This is how we swap it
		}
	}
// Finish
}
/**
*  *  This function swaps the values of two integers.
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*/
void swap(int* a, int* b)
{
	int temp; //temp variable
	temp = *a; //saves a
	*a = *b; //makes a now == b
	*b = temp; // gives b old a
// Finish
}
/** 
This function compares two integers for ascending order
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*  @return true if a > b, else false
*
*/
bool ascending(int a, int b)
{
	if (a > b) { //self explanatory
		return 1;
	}
	else {
		return 0;
	}
// Finish
}
/**
*  This function compares two integers for descending order
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*  @return true if a < b, else false
*/
bool descending(int a, int b)
{
	if (a < b) { //self explanatory
		return 1;
	}
	else {
		return 0;
	}
// Finish
}