#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int SIZE = 25;
int numbers[SIZE];

int countSevens(const char *str){
  int count = 0;
  const char *p = str;
  for(int i = 0; i < SIZE; i++){
    if(*p == 7){
      count++;
    }
  }
  return count;
}
int add(int arr[]){
  int total = 0;
  int sevenCounter = 0;
  int numCount = 0;
  char numString[256];
  char temp[100];
  for(int i = 0; i < SIZE; i++){
    if(arr[i]==-9999){
      break;
    }else{
    total+=arr[i];
    numCount++;
    sprintf(temp, "%d", arr[i]);
    strcat(numString,temp);
    }
  }
  printf("Total: %d Average: %d String Version: %s\n", total, total/numCount, numString);
  printf("Number of 7's: %d\n", countSevens(numString));
  return total;
}

int main( int argc, char * argv[] ) {
int counter = 0;
  while(1){
    int temp;
    printf("Enter number: ");
    scanf("%d", &temp);
    if(temp == -9999){
      numbers[counter] = temp;
      break;      
    }
    numbers[counter] = temp;
    counter++;
  }
  int total = add(numbers);
  
}
