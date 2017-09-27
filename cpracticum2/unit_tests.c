// unit_tests.c
// Larry Kiser Nov. 29, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "cpracticum2.h"
#include "unit_tests.h"

// used by stdout switching functions
static int stdout_file_descriptor = 0 ;
static fpos_t stdout_position ;

// Redirect printf's to the specified text file (redirect stdout).
static void switch_stdout_to_file( char *filename )
{
	fflush( stdout ) ;
	fgetpos( stdout, &stdout_position ) ;
	stdout_file_descriptor = dup( fileno( stdout ) ) ;
	freopen( filename, "w", stdout ) ;
}

// Restore normal printf behavior (restore stdout).
// MUST be called only after a prior call to switch_stdout_to_file!
static void restore_stdout( void )
{
	if ( stdout_file_descriptor )
	{
		fflush( stdout ) ;
		dup2( stdout_file_descriptor, fileno( stdout ) ) ;
		close( stdout_file_descriptor ) ;
		clearerr( stdout ) ;
		fsetpos( stdout, &stdout_position ) ;
	}
}

// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	// bogus code that does nothing except avoid compiler warning on these two unused functions.
	#pragma GCC diagnostic ignored "-Waddress"
	if ( switch_stdout_to_file && restore_stdout ) ;
	#pragma GCC diagnostic warning "-Waddress"
	
	if ( ! test_result ) {
		va_start( arguments, error_format ) ;
		printf( "Test # %d failed: ", test_number ) ;
		vprintf( error_format, arguments ) ;
		printf( "\n" ) ;
		result = 0 ;
	}
	test_number++ ;
	return result ;
}

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
int test()
{
	int passcount = 0 ;
	int failcount = 0 ;
	int firstArray[] = { 1, 2, 3, 4, 5, 6 } ;
	int secondArray[] = { 5, 6, 7, 8, 9, 10 } ;
	
	int result = 0 ;
	double answer = 0.0 ;
	
	printf( "\nTests for is_pointer_in_array.......................\n" ) ;
	// Test 1
	result = is_pointer_in_array( firstArray, firstArray, sizeof(firstArray) / sizeof(int) ) ;
	assert( result == 1,
		"Points to the first position in the array so expected a 1 but got a %d",  result )
		? passcount++ : failcount++ ;
	// Test 2
	result = is_pointer_in_array( firstArray, &firstArray[5], sizeof(firstArray) / sizeof(int) ) ;
	assert( result == 1,
		"Points to the last position in the array so expected a 1 but got a %d",  result )
		? passcount++ : failcount++ ;
	// Test 3
	result = is_pointer_in_array( firstArray, &firstArray[6], sizeof(firstArray) / sizeof(int) ) ;
	assert( result == 0,
		"Points to an invalid position just past the end of the array so expected a 0 but got a %d",  result )
		? passcount++ : failcount++ ;

	printf( "\nTests for my_random()...............................\n" ) ;
	// Test 4
	assert( ( answer = my_random() ) == 0.22,
		"First random number must be 0.22 but got a %f",  answer )
		? passcount++ : failcount++ ;
	// Test 5
	assert( ( answer = my_random() ) == 0.88,
		"Second random number must be 0.88 but got a %f",  answer )
		? passcount++ : failcount++ ;
	// Test 6
	my_random() ;	// skip next four numbers
	my_random() ;
	my_random() ;
	my_random() ;
	assert( ( answer = my_random() ) == 0.02,
		"Last random number must be 0.02 but got a %f",  answer )
		? passcount++ : failcount++ ;
	// Test 7
	assert( ( answer = my_random() ) == 0.22,
		"Must now be back at the first random number of 0.22 but got a %f",  answer )
		? passcount++ : failcount++ ;

	printf( "\nTests for add_array_values..........................\n" ) ;
	// Test 8
	result = add_array_values( firstArray, secondArray, sizeof( firstArray ) / sizeof( int ) ) ;
	assert( firstArray[5] == 16,
		"The last entry in the updated first array should be 16 but got %d",  firstArray[5] )
		? passcount++ : failcount++ ;
	// Test 9
	assert( result == 66,
		"Sum of the updated first array should be 66 but got %d",  result )
		? passcount++ : failcount++ ;
	// Test 10
	result = add_array_values( firstArray, secondArray, 0 ) ;
	assert( result == 0,
		"Expected 0 because number of entries is 0 but got %d",  result )
		? passcount++ : failcount++ ;
	// Test 11
	result = add_array_values( firstArray, NULL, sizeof( firstArray ) / sizeof( int ) ) ;
	assert( result == 0,
		"Expected 0 because second array is a null pointer but got %d",  result )
		? passcount++ : failcount++ ;	
	// Test 12
	result = add_array_values( NULL, secondArray, sizeof( firstArray ) / sizeof( int ) ) ;
	assert( result == 0,
		"Expected 0 because first array is a null pointer but got %d",  result )
		? passcount++ : failcount++ ;
		
	printf( "\nTests for fix_bad_code..............................\n" ) ;
	// Test 13
	assert( ( result = fix_bad_code( "test" ) ) == 0,
		"Expected 0 because there are no digits but got %d",  result )
		? passcount++ : failcount++ ;
	// Test 14
	assert( ( result = fix_bad_code( "test1" ) ) == 1,
		"Expected 1 because there is one digit but got %d",  result )
		? passcount++ : failcount++ ;
	// Test 15
	assert( ( result = fix_bad_code( "" ) ) == 0,
		"Expected 0 because it is an empty string but got %d",  result )
		? passcount++ : failcount++ ;
	// Test 16
	assert( ( result = fix_bad_code( NULL ) ) == 0,
		"Expected 0 because the string pointer is a null pointer but got %d",  result )
		? passcount++ : failcount++ ;
		
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}