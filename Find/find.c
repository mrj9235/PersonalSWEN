/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdbool.h>

#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
	int index = 0;
	while(string[index]){
		if(string[index] == ch){
			return index;
		}
	index++;
	}
	return NOT_FOUND ;	// placeholder
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
	while(*string){
		if(*string == ch){
			return string;
		}
	*string++;
	}
	return NULL ;	// placeholder
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
	int indexStop;
	int indexString =0;
	int result;
	while(string[indexString]){
		indexStop = 0;
		while(stop[indexStop]){
			if(stop[indexStop] == string[indexString]){
				return indexString;
				}
			else{
				indexStop++;
			}
		}
		indexString++;
	}
	return NOT_FOUND ;	// placeholder
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char *stop) {
	char *s;
	while(*string){
		s = stop;
		while(*s){
			if(*string == *s){
				return string;
			}
			else{
				s++;
			}
		}
		string++;
	}

	return NULL ;	// placeholder
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char *substr) {
	char *str;
	char *s;
	if(*substr == '\0'){
		return string;
	}
	while(*string){
		s = string;
		str = substr;
		while(*str == *s){
			str++;
			s++;
			if( *str =='\0'){
				return string;
			}
		}
		string++;
	}
	return NULL ;	// placeholder
}
