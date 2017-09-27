#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main(int ac, char **argv) {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */
	int c = getchar(); 	// c becomes the int that getchar() returns
	int g = c;		// second variable to keep track of words
	/* REPLACE WITH ADDITIONAL VARIABLE DECLARATIONS YOU NEED */

	/* REPLACE WITH THE CODE FOR WORD COUNT */
	if( c != ' ' && c != '\n'){
		tot_words++;
	}
	while ( c != EOF){
		tot_chars ++;
		if( c == '\n'){
			tot_lines ++;
		}
		else if(g == '\n' && (c != '\n' || c != ' ')){
			tot_words ++;
		}
		else if(c == ' ' && g != ' '){
			tot_words ++;
		}
		g = c;
		c = getchar();
	}
	printf(" %i %3i %2i \n", tot_lines, tot_words, tot_chars);
	return 0 ;
}
