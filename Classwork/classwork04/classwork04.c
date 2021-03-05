#include <stdio.h>
#include <stdbool.h>
#include "main.h"

const int timeSlice = 40;
bool threadA = true;
bool threadB = true;
bool threadC = true;
bool threadD = true;


int main(int argc, char * argv[]){
  char A = 'A';
  int aTime = 100;
  char B = 'B';
  int bTime = 200;
  char C = 'C';
  int cTime = 130;
  char D = 'D';
  int dTime = 74;

  while(threadA || threadB || threadC || threadD ){
    if(threadA){
      run(A, &aTime, &threadA);
     }
     if(threadB){
       run(B, &bTime, &threadB);
     }
     if(threadC){
       run(C, &cTime, &threadC);
     }
     if(threadD){
       run(D, &dTime, &threadD);              
    }
  }
return 0;
}

void run(char A, int *time, bool *thread){
  if(*time > timeSlice){
    *time -= timeSlice;
    printf("%c:%d:%d\n", A, timeSlice, *time);
  }else if(timeSlice > *time && *time > 0){
    printf("%c:%d:Done\n", A, *time);
    *thread = false;
  }
}