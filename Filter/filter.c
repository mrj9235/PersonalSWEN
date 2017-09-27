/*
 * Implementation of functions that filter values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h> OTHER THAN
 * strcpy() and strlen()
 *****
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filter.h"

#define NUL ('\0')

/*
 * YOU MAY FIND THIS FUNCTION USEFUL.
 * Return true if and only if character <c> is in string <s>.
 */
static bool includes(char c, char *s) {
	while( *s && c != *s ) {
		s++ ;
	}
	return c == *s ;
}

/*
 * YOU MAY ALSO FIND THIS FUNCTION USEFUL.
 * Return true if and only if string <pre> is a prefix of string <s>.
 */
static bool prefix(char *s, char *pre) {
	while( *pre && *s == *pre ) {
		s++ ;
		pre++ ;
	}
	return *pre == NUL ;
}

/*
 * Copy <string> to <result> while removing all occurrences of <ch>.
 */
void filter_ch_index(char string[], char result[], char ch) {
	int iS = 0;
	int iR =0;
	while(string[iS]){
		if(string[iS] == ch){
			iS++;
		}
		else{
			result[iR] = string[iS];
			iR++;
			iS++;
		}
	}
	result[iR] = NUL;
}

/*
 * Return a pointer to a string that is a copy of <string> with
 * all occurrences of <ch> removed. The returned string must occupy
 * the least possible dynamically allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_ch_ptr(char *string, char ch) {
	char *p_copy = malloc(sizeof(*string)+ 1);
	char *p = p_copy;
	while(*string){
		if(*string == ch){
			string++;
		}
		else{
			*p = *string;
			p++;
			string++;
		}
	}
	*p = NUL;
	p = malloc(sizeof(*p_copy));
	strcpy(p,p_copy);
	free(p_copy);
	return p; 
}

/*
 * Copy <string> to <result> while removing all occurrences of
 * any characters in <remove>.
 */
void filter_any_index(char string[], char result[], char remove[]) {
	int indexS= 0;
	int indexR = 0;
	int indexResult = 0;
	int resultI = 0;
	if(remove[indexR] == NUL){
		for(indexS = 0; string[indexS]; indexS++){
			result[indexS] = string[indexS];
		}
		result[indexS] = NUL;
	}
	while(string[indexS]){
		resultI--;
		for(indexR = 0; remove[indexR]; indexR++){
			if(remove[indexR] == string[indexS]){
				resultI++;
				break;
			}
		}
		if(result != 1){
			result[indexResult] = string[indexS];
			indexResult++;
		}
		indexS++;
	}
	result[indexResult]= NUL;

}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of any characters in <remove>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_any_ptr(char *string, char* remove) {
	return strcpy(malloc(1), "") ; // placeholder
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of the substring <substr>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE ARRAY INDEXING.
 *****
 */
char *filter_substr(char *string, char* substr) {
	return strcpy(malloc(1), "") ; // placeholder
}
