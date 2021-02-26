#include <stdio.h>
#include <stdlib.h>



int randomInt(){
  printf("%d", rand() % 101);
  return rand() % 101;
}

int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  int* arr = malloc(size);
  for(int i = 0; i < size; i++){
  int random = rand() % 101;
    arr[i] = rand()%101;
    printf("%d:", arr[i]);
  }
  printf("Array has been populated\n");
  free(arr);
}
