// C (no pointers) Practice Practicum
// SWEN-250
// Larry Kiser February 9, 2016

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpractice1.h"
#include "unit_tests.h"


// Returns the index position of the first letter found starting at mystring[ start_index ].
// 1. If mystring[ start_index ] is a letter it returns the value of start_index.
// 2. If mystring[ start_index ] is a space then it moves to the next position
//    until it either sees the end of the string or it sees a letter.
//    If no letter is found it returns a -1 to indicate no letter found.
// 3. If mystring[ start_index ] is an end of string then return -1.
// You are NOT allowed to use any library functions to do this.
// You can assume that the string only contains letters and spaces.
// Hint: Use this assumption to simplify your code!
int skip_spaces( char mystring[], int start_index )
{
	while( mystring[ start_index ] != '\0')
	{
		if(mystring[ start_index ] == ' ')
		{
			start_index ++;
		}
		else
		{
			return start_index;
		}
	}
	if( mystring[ start_index ] == '\0')
	{
		return -1;
	}
}

// Returns the index position of the first letter of the next word starting at mystring[ start_index ].
// 1. If mystring[ start_index ] is a letter it searches for the first space.
//    If it finds a space it skips spaces searching for a letter.
//    If a letter is found it returns this letter's index position since this is the beginning of the next word.
//    If no letter is found it returns a -1.
// 2. If mystring[ start_index ] is a space it searches until it either sees
//    the end of the string or it sees a letter.
//    If no letter is found it returns a -1.
// 3. If mystring[ start_index ] is an end of string return a -1.
// You are NOT allowed to use any library functions to do this.
// You can assume that the string only contains letters and spaces.
// HINT: Use skip_spaces to simplify this function.
int find_next_word( char mystring[], int start_index )
{
	int c = -1;
	if(mystring[ start_index ] != ' ')
	{
		while( mystring[ start_index ] != ' ')
		{
			if(mystring[ start_index ] == '\0'){
				return -1;
			}
			else{
				start_index++;
			}
		}
		c = skip_spaces(mystring, start_index);
		return c;
	}
	else
	{
		c = skip_spaces(mystring, start_index);
		return c;
	}
}

// If mystring[ index ] is a lower case letter this function replaces
// that letter in the array with the corresponding upper case letter.
// 1. If mystring[ index ] is an upper case letter, a space, or an end of string it makes no change.
//    This function returns 0 when it makes no change.
// 2. This function returns a 1 only when it changes a lower case letter to an upper case letter.
// You are NOT allowed to use any library functions to do this.
// HINTS: upper case letters are decimal 65 through decimal 90.
// lower case letters are decimal 97 through decimal 122.
int change_to_upper( char mystring[], int index )
{
	int c = mystring[index];
	if( c <= 90 && c >= 65 || c == ' ' || c == '\0'){
		return 0;
	}
	else{
		c = c - 32;
		mystring[index] = c;
		return 1;
	}
}

// This function finds the first letter of every word in mystring[]
// and makes sure that is is a capital letter.
// If it is a lower case letter it converts it to upper case (just the first letter in the word).
// It returns a count of the number of letters it actually converted to upper case.
// If mystring[] is an empty string it returns 0.
// Hint: First skip leading spaces. Then loop while on a word, capitialize the word,
//       and then find the next word.
int capitialize_all_words( char mystring[] )
{
	int index = 0;
	int changed = 0;
	int c = 0;
	if(mystring[index] == '\0'){
		return 0;
	}
	index = skip_spaces(mystring, index);
	while(index != -1){
		c = change_to_upper(mystring, index);
		if( c == 1){
			changed ++;
		}
		index = find_next_word(mystring, index);
	}
    return changed;
}

// Run the unit tests or as a "normal program".
int main( int argc, char *argv[] ) {

    // Execute unit tests if program name contains "test".
    if ( strstr( argv[0], "test" ) )
        return test() ;

    printf( "\nDoes nothing -- please run unit tests instead.\n\n" ) ;
    
    return 0 ;
}
