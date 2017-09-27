#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "julius.h"


/* readline:
 *	Read a line of limited size lim into s,
 *	Return 0 if EOF was encountered, 1 otherwise.
 *	Terminate with a null character. Discard the newline character.
 */
int readline( char s[], int lim ) {
	int i = 0;
	int c = getchar();
	while( c != '\n'){
                if(i < lim){
                        if( c != EOF){
                                s[i] = c;
                                i ++;
                        }
                        else if( c == EOF){
                                return 0;
                        }
		c = getchar();
		}
	}
	s[i] = '\0';
	return 1;

}

/*
 * julius:
 *	Perform the rotation encipher on the characters in the string
 * 	passed in as a character array by calling encipher on each character in  *   the string
 */
void julius(char string[]) {

	// ADD YOUR CODE HERE
	// Loop through the array, calling encipher(char), until the end of string.
	int i = 0;
	char c;
	while(string[i] != '\0'){
		c = string[i];
		string[i] = encipher(c);
		i ++;
	}
}

/*
 * encipher:
 *	given a character of ASCII code 33 to 79, translate to 80 to 126 and
 *	vice versa.
 * *
*/
char encipher(char c){
	if(c <= 126 && c >= 80){
		c = c - 47;
		return c;
	}
	else if( c == ' ' || c == '\n'){
		return c;
	}
	else{
		c = c + 47;
		return c;
	}
}
