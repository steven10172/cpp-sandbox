#include <iostream>
#include <stdio.h>
#include <stdlib.h>


void reverse(char* str) {
  int len = strlen(str);
  char reversed[len + 1];

  int position = 0;
  for(int i=len-1; i >= 0; i--) {
    reversed[position++] = str[i];
  }
  reversed[position] = '\0';

  //*str = *reversed;

  printf("Size: %d\n", strlen(reversed));
  printf("Size: %lu\n", strlen(reversed));
  printf("Reversed: %s\n", reversed);
  //char reversed[] = str;
}

int main() {
  char str[] = "ABC";
  
  reverse(str);
  
  printf("%s\n", str);

  return 0;
}