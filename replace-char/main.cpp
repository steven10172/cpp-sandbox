#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void replaceSpaces(char* str) {
  //int len = strlen(str);

  for(int i=0; i<strlen(str); i++) {
    if(str[i] == ' ') {
      for(int j=strlen(str)as; j >= i; j--) {
        str[j+2] = str[j];
      }
      str[i] = '%';
      str[i+1] = '2';
      str[i+2] = '0';
      i += 2;
    }
  }
}

int main() {
  char str[20] = "Cars 4 sale";

  printf("Original: %s\n", str);

  replaceSpaces(str);
  printf("Updated: %s\n", str);

  return 0;
}