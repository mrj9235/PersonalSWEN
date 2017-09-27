/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"
#define MAX_CHARS 25
// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.
void read_data( char *cp, int *ip, double *dp ) {
	char c;
	char i[MAX_CHARS];
	char d[MAX_CHARS];
	int data = getchar();
	int index = 0;
	while(data != '$'){
		c = data;
		data = getchar();
	}
	data = getchar();
	while(data != '$' && index < MAX_CHARS){
		i[index] = data;
		index++;
		data = getchar();
	}
	index = 0;
	data = getchar();
	while(data != '$' && index < MAX_CHARS){
		d[index]= data;
		index ++;
		data = getchar();
	}
	*cp = c;
	*ip = atoi(i);
	*dp = atof(d);

}
