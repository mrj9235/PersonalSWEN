// C pointers light Practice Practicum
// SWEN-250
// Larry Kiser October 30, 2015
// Updated March 27, 2017

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpracticum2.h"
#include "unit_tests.h"

// Determine if the p_unknown pointer points to one of the integers in the  array of integers.
// You need to use num_int_in_array -- this is the number of integers in the p_int_array array.
// return 1 if it does, return 0 otherwise.
int is_pointer_in_array( int *p_int_array, int *p_unknown, int num_int_in_array )
{
	int i = 0;
	while(i < num_int_in_array){
		if(p_int_array == p_unknown){
			return 1;
		}
		*p_int_array++;
		i++;
	}
	return 0;
}

// The first time this is called return the first double in the mylist array.
// The second time this is called return the second double in the mylist array.
// On subsequent calls return the next entry in mylist.
// HOWEVER, after you return the last item in the array the next call must return
// the first element in the array.
// HINT -- this means that somehow you must remember the position of the last number
//         you returned. You CANNOT change the call to my_random in any way.
double my_random()
{
	static int index = 0;
	double mylist[] = { 0.22, 0.88, 0.98, 0.40, 0.07, 0.51, 0.02 } ; // DO NOT change this array!
	if(index <= 6){
		index++;
	}
	else if( index == 7 ){
		index = 0;
		index++;
	}
	return mylist[index - 1];
}


// Add each entry in a second array of integers to the corresponding entry in the
// first array of integers.
// It returns the sum of the updated values in the first array.
// Both arrays are the same size.
// The third parameter is the number of entries in each array.
// Return 0 if either array pointer is NULL.
// Return 0 if the number of entries is <= 0.
int add_array_values( int *p_first, int *p_second, int number_of_entries )
{
	int i = 0;
	int sum = 0;
	if(number_of_entries < 0){
		return 0;
	}
	while(i < number_of_entries){
		if(!p_first || !p_second){
			return 0;
		}
		*p_first += *p_second;
		sum += *p_first;
		p_first++;
		p_second++;
		i++;
	}
	return sum;
}

// This function is implemented incorrectly. Fix it to pass the unit tests.
// When fixed it returns 1 if there are any digits (0 through 9) anywhere in the passed string.
// If there are no digits it returns 0.
// It also returns 0 if the passed string pointer is NULL or if the string points to an empty string.
// You can re-write this code completely if you prefer.
int fix_bad_code( char *p_string )
{
	int result = 0;	// is this a good choice for initialization?
	int digit;
	// Fix this next line so it correctly returns 0 if the passed pointer is NULL or
	// if the pointer points to an empty string.
	if ( (!p_string) || *p_string == '\0'  ){
		return result ;
	}
	// does this loop work correctly?
	while ( *p_string ){
		if (isdigit(*p_string)){  // isdigit returns true if the passed character is a number 0 through 9
			digit = atoi(p_string);
			if(digit >= 0 && digit <= 9){
				result = 1;
				return result;
			}
		}
		else{
			p_string++;
		}
	}
	return result ;
}
