#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "julius.h"
//extern int readline( char s[], int lim );
//extern void julius( char string[] );

int main() {
	// ADD YOUR CODE BELOW
	// Declare any variables, including arrays you need here:
	char line[MAXLINESIZE];
	int i;
	// General instruction:
	// Read lines from standard input until EOF is encountered.
	// Note: (readline shall discard the newline character and properly terminate the
	//  string holding the line).

		// Upon receiving a line, call julius with the string to encipher the text.
		//   (julius will call encipher(char) on each character)

		// Print out the resulting string as a separate line to standard output
	while( (i = readline(line, MAXLINESIZE)) == 1){
		julius(line);
		printf("%s\n", line);
	}

	return 0 ;
}
