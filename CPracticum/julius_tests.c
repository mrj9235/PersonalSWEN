#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "julius.h"

int main(){
  printf("-----Check these results manually!---\n");
  printf("TEST 1. encipher('a') is '2' ==> '%c'\n", encipher('a'));
  printf("TEST 2. encipher('H') is 'w' ==> '%c'\n", encipher('H'));
  printf("TEST 3. encipher(' ') is ' ' ==> '%c' (space)\n", encipher(' '));
  printf("-------------------------------------\n");

  char str1[MAXLINESIZE+1] = "w6==@[ H@C=5P";
  julius(str1);
  printf("TEST 4. julius(\"w6==@[ H@C=5P\") is \"Hello, world!\" ==> %s\n", str1);

  char str2[MAXLINESIZE+1] = "Hello, world!";
  julius(str2);
  printf("TEST 5. julius(\"Hello, world!\") is \"w6==@[ H@C=5P\" ==> %s\n", str2);

  char str3[MAXLINESIZE+1] = "Four";
  julius(str3);
  printf("TEST 6. julius(\"Four\") is \"u@FC\" ==> %s\n", str3);

  printf("-------------------------------------------\n");
  printf("DON'T FORGET TO ALSO TEST readline via command line\n");
  printf("-------------------------------------------\n");

  return 0;
}
