/**
*  FileName:    Sorting.h
*  Author:
*  Date:
*  Used by: August Koehler
*  Description:  Functions for sorting. Bubble sort, Selection Sort
*/
#pragma once
/**
*  This function sorts integers based on function pointers to 
*    a desired sorting function and desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param alg  - function pointer to sorting algorithm
*  @param cmp  - function pointer to comparision function
*
*/
void sortArray(int* values, int n, void(*alg)(int*, int, bool (*cmp)(int,int)), bool(*)(int,int) );
/**
*  This function sorts integers using the bubble sort method 
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void bubbleSort(int* values, int n, bool (*cmp)(int,int));
/**
*  This function sorts integers using the selection sort method 
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void selectionSort(int* values, int n, bool (*cmp)(int,int));
/**
*  This function swaps the values of two integers.
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*/
void swap(int* a, int* b);
/**
*  This function sorts integers using the selection sort method 
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
bool ascending(int a, int b);
/**
*  This function compares two integers for descending order
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*  @return true if a < b, else false
*/
bool descending(int a, int b);
