#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  int size = 4096;
  int* arr = malloc(size);
  for(int i = 0; i < size; i++){
  int random = rand() % 101;
    arr[i] = rand()%101;
    printf("%d:", arr[i]);
  }
  printf("Array has been populated\n");
  printf("%d",arr[4095]);
  printf("%d",arr[694]);
  printf("%d",arr[300]);
  //free(arr);
}


int randomInt(){
  printf("%d", rand() % 101);
  return rand() % 101; 
}