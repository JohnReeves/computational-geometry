/************************
   build with:
     gcc hello.c -o hello
   run with:
     ./hello
*************************/

#include <stdio.h>

int main() {
  // learn the build cylce 
  char c;
  printf("Hello, Mate!\n\n");

  printf("Enter a character: \n");
  printf("^C or 'stop' to stop \n");

  // display the integer value of a character
  // and the actual character
  while (scanf("%c", &c) != EOF)
    if (c != '\n')
      printf("ASCII value of %c = %d\nanother character (or ^C): ", c, c);

  return 0;
}

