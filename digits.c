/*
File Name: digits

Author: August Koehler

Class: Computational Problem Solving for Engineers

Section: 03

Program Intent: to separate the individual digits of a positive integer <= 10 digits and give a table of the number of occurences. If each is unique, determine whether it is divisible by the digits and say what up.

Input Data: positive integer of <= 10 digits

Output Data: A table of the number of occurences or whether it is divisible by the individual digits.
*/

/*---------------
Include Section
----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

void separator( long int n);
void disptable( int r[], int size);
int different( int z[], int size);
int divisible(int z[], int size, long int n);
int size = 10;
/*--------------------------- main function -------------------------------
Purpose: To accept inputs and control the other functions

Returns: EXIT_SUCCESS
---------------------------------------------------------------------------*/

int main( )
{
	long int input;
	printf("Enter a positive integer or 0 (zero) to end: ");
	scanf("%li", &input);
	while ( input != 0) {
		if (input < 0) {
			puts("Wrong input");
		}
		else {
			separator(input);
		}
		printf("\n\nEnter a positive integer or 0 (zero) to end: ");
		scanf("%li", &input);
	}
	puts("*** Program Terminated ***");
   return (EXIT_SUCCESS);
}


/*--------------------------- digit separator function -------------------------------
Purpose: separates the digits of the input

Returns: void!
---------------------------------------------------------------------------*/
void separator( long int n) 
{
	int a[10]= {0}, digit;
	long int num = n;
	while (num > 0) {
		digit = num % 10;
		++a[digit];
		num /= 10;
	}
	disptable( a, 10);
	if (a[0] != 0) {
		printf("Wrong input for the second part.\nInput should not contain zero.\n");
	}
	else if (different(a, 10) == FALSE) {
		printf("Wrong input for the second part.\nInput should not contain each digit more than once.\n");
	}
	else if (divisible(a, 10, n) == FALSE) {
		printf("%ld is not divisible by its digits.\n", n);
	}
	else {
		printf("%ld is divisible by its digits", n);
	}
}


/*--------------------------- display table function -------------------------------
Purpose: to display the table with the given format

Returns: 
---------------------------------------------------------------------------*/
void disptable( int r[], int size) 
{
	printf("\n\n");
	printf("Digits:         0  1  2  3  4  5  6  7  8  9\nOccurances:   ");
	int i;
	for (i=0; i< size; i++) {
		printf("  %d", r[i]);
	}
	puts("\n");
}

/*--------------------------- different ?? function -------------------------------
Purpose: determines whether one digit is different from the other

Returns: true or false depending on the value of that array element
---------------------------------------------------------------------------*/
int different( int z[], int size) 
{
	int i;
	for (i=0; i<size; i++) {
		if ( z[i] > 1) {
			return FALSE;
		}
	}	
	return TRUE;
		
	}


/*--------------------------- divisible by digits function -------------------------------
Purpose: To determine whether the original integer is divisible by any of its digits

Returns: TRUE or FALSE depending on whether it is true or false...
---------------------------------------------------------------------------*/
int divisible( int z[], int size, long int n)
{
	int i;
	for (i =0; i<size; i++) {
		if (z[i] == 0) {
			continue;
		}
		else if (n % i != 0) {
			return FALSE;
		}
	}
	return TRUE;
}

/*------------------Q-u-e-s-t-i-o-n- -t-i-m-e-----
a) Largest int divisible by all of its digits? 
I haven't the time nor brainpower to do this part right now :C I tried writing the bit from part c to find this but I gotta sleep so that's a no no for this assignment. Thank you for letting me turn it in so far past the due date. The program works as far as I can tell.


b)
Same here


c) This one is easier than the first 2. I'd write a function (or addition/change to main) with a loop that starts at the top of the acceptable range of inputs, then have it go through everything else and have it alert on the first two occurances of where divisible( a, 10, n) is true.


--------------------------*/