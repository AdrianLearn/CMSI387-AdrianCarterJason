#include <stdio.h>

int main(void) {
  int evenCounter,oddCounter = 0;
  for (int i = -10; i <= 10; i++){
    int square = i*i;    
    if(square % 2 == 0){
      evenCounter++;
      printf("%d\t%d\t%s\n", i, square, "EVEN");
    }else{
      oddCounter++;
      printf("%d\t%d\t%s\n", i, square, "ODD");
    }
  }
  printf("# odd numbers = %d\n# even numbers = %d\n", oddCounter, evenCounter);
}
