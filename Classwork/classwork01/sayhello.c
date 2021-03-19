#include <stdio.h>
#include <stdlib.h>

int main () {
   char str[50];

   printf("Enter your name : ");
   gets(str);

   printf("Hello, %s", str);

   return(0);
}