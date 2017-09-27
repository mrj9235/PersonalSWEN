// unit_tests.c
// Larry L. Kiser Oct. 22, 2015
// Copyright 2015 All Rights Reserved

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "linked.h"
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
	int test_data;
	
	// bogus code that does nothing except avoid compiler warning on these two unused functions.
	#pragma GCC diagnostic ignored "-Waddress"
	if ( switch_stdout_to_file && restore_stdout ) ;
	#pragma GCC diagnostic warning "-Waddress"
	
	// Test 1 -- check that list length is 0
	assert( length() == 0,
		"Length of list must initially be zero" )
		? passcount++ : failcount++ ;
	//Tests 2 and 3 to see if Push worked
	push(1);
	assert(length() == 1, "Length of list should be 1" ) ? passcount++ : failcount++;
	push(2);
	assert( length() == 2, 
		"Length of list should now be 2" )
		? passcount++ : failcount++ ;
	//Tests 4-7 to see if pop worked, popped until list is empty
	test_data = pop();
	assert(test_data == 2, "The data removed should equal 2") ? passcount++ : failcount++;
	assert(length() == 1, "Length of list after pop should be 1" ) ? passcount++ : failcount++;
	test_data = pop();
        assert(test_data == 1, "The data removed should equal 2") ? passcount++ : failcount++;
        assert(length() == 0, "Length of list after pop should be 1" ) ? passcount++ : failcount++;
	//Test 8 -- will push one element and then append another and will pop to see if it ended up in the right spot
	push(1);
	appendNode(3);
	pop();
	assert(pop()== 3, "Data popped should be 3") ? passcount++ : failcount++;
	//Test 9 -- will push 3 elements and then append another and will pop to see if it ended in the right spot.
	push(1);
	push(2);
	push(3);
	appendNode(5);
	pop();
	pop();
	pop();
	assert(pop() == 5, "Data popped should equal 5") ? passcount++ : failcount++;
	//Test 10
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	struct node* cpy = copyList();
	assert(compareList(cpy) == 1, "List should return 1 if equal") ? passcount++ : failcount++;
	//Test 11 -- tests free list on a list with 5 elements
	assert(freeList() == 1, "Free the shit") ? passcount++: failcount++;
	//Test 12 -- tests the freeList on an empty function
	pop();
	pop();
	pop();
	pop();
	pop();
	assert(freeList() == 1, "Freeing an empty List") ? passcount++ : failcount++;
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	return failcount ;
}
