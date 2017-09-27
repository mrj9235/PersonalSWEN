/*
 * Skeleton implementation for the activity to parse and print
 * CSV formatted files read from standard input.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csv.h"
#include "unit_tests.h"


/*
 * Returns true if the character 'ch' ends a field. That is, ch is end of file,
 * a comma, or a newline.
 */

bool is_end_of_field(int ch) {
	return (ch == ',') || (ch == '\n') || (ch == EOF) ;
}

/*
 * Return the minimum of two integers.
 */

int min(int x, int y) {
	return x < y ? x : y ;
}

/*
 * Read the next field from standard input. Returns the value of getchar() that
 * stopped (terminated) the field.
 */

int get_field(f_string field) {
	/* FILL THIS IN */
	int c = getchar(); //c will be updated to get each individual character
	int i = 0; // a counter
	for( c; c!= '\0'; c = getchar()){ //a for loop that ends when c == a terminator
		if(is_end_of_field(c)){
			field[i] = '\0'; //adds terminator to end of field
			return c;
		}
		else{
			field[i] = c;
			i ++;
		}
	}

}

/*
 * Read in a CSV line. No error checking is done on the number of fields or
 * the size of any one field.
 * On return, the fields have been filled in (and properly NUL-terminated), and
 * nfields is the count of the number of valid fields.
 * nfields == 0 means end of file was encountered.
 */

csv_line get_line() {
	/* FILL THIS IN */
	int i = 0; //counter
	csv_line line; //creates a new csv_line object
	int c; // keeps track of the last c line
	while( c != EOF && c != '\n'){ // a while loop that ends when c is either \n or EOF
		c = get_field(line.field[i]);
		i ++;
		line.nfields ++;
	}
	if( c == EOF){
		line.nfields = 0;
	}
	return line;
}

/*
 * Print a CSV line, associating the header fields with the
 * data line fields.
 * The minimum of the number of fields in the header and the data
 * determines how many fields are printed.
 */

void print_csv(csv_line header, csv_line data) {
	/* FILL THIS IN */
	int i=0; // counter
	int m= min(header.nfields, data.nfields);// determines which one has the least amount of fields
	while(i < m){ // while loop that ends when i == m
		printf("%s = %s\n", header.field[i], data.field[i]);
		i ++;
	}
}

/*
 * Driver - read a CSV line for the header then read and print data lines
 * until end of file.
 */

int main( int argc, char *argv[] ) {
	csv_line header ;
	csv_line current ;

	// LLK additional if statement to execute unit tests if program
	// name contains "test".
	if ( strstr( argv[0], "test" ) )
		return test() ;

	header = get_line() ;
	current = get_line() ;

	while ( current.nfields > 0 ) {
		print_csv(header, current) ;
		current = get_line() ;
	}

	return 0 ;
}
