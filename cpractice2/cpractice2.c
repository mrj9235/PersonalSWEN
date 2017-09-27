// C pointers light Practice Practicum
// SWEN-250
// Larry Kiser October 30, 2015

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpractice2.h"
#include "unit_tests.h"

// return a pointer to the character that is at the passed position.
// return a null if the requested position is past the end of the string.
char *get_pointer_at_position( char *pstring, int position )
{
	int i = 0;
	while(*pstring){
		if(i ==  position){
			return pstring;
		}
		else{
			*pstring++;
			i++;
		}
	}
	return NULL;
}

// Convert array of integer x values into an array of y values using y = mx + b where m and b are constants
// passed to the function. The x values will be replaced by the y values (the x values are overwritten).
// The constants can be positive, negative or zero.
// Return the sum of the y values.
// Return 0 if the passed in px pointer is NULL.
int convert_and_sum( int *px, int m, int b, int number_of_x_values )
{
	int y = 0;
	int i = 0;
	int sum = 0;
	if(px == NULL){
		return 0;
	}
	for( i; i < number_of_x_values; i++){
		*px *= m;
		*px += b;
		sum += *px;
		px ++;
	}
	return sum;
}

// Determine if two pointers point to the same array of numbers
// return 1 if they do, return 0 otherwise.
// return 0 if either pointer is NULL.
int same_array( int *pfirst, int *psecond )
{

	if( pfirst == NULL || psecond == NULL){
		return 0;
	}
	else{
		if( pfirst == psecond ){
			return 1;
		}
	}
	return 0;
}

// The first time this is called return 1.
// The second time this is called return 0.
// Continue this pattern returning 1, then 0, then 1 and so on.
int num_runs = 0;
int bool_flip_flop()
{
	if(num_runs % 2 == 0){
		num_runs++;
		return 1;
	}
	num_runs++;
	return 0 ;	// Fix this -- it is incorrect but allows the program to compile and run.
}

// This function is implemented incorrectly. You need to correct it.
// When fixed it changes the last character in the passed string to 'Z'.
// It returns returns 1 on success.
// It returns 0 on if the passed string is NULL or an empty string.
int fix_bad_code( char *pstring )
{
	int i = 0;
	if( *pstring == '\0' || pstring == NULL){
		return 0 ;
	}
	while( *(pstring+i) != '\0' ){
		i++;
	}
	i--;
	*(pstring+ i) = 'Z' ;
	return 1 ;
}
