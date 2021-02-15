#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int timeSlice = 40;
  bool threadA = true;
  bool threadB = true;
  bool threadC = true;
  bool threadD = true;
int main(int argc, char *argv[]){
  char* A = argv[1];
  int aTime = atoi(argv[2]);
  char* B = argv[3];
  int bTime = atoi(argv[4]);
  char* C = argv[5];
  int cTime = atoi(argv[6]);
  char* D = argv[7];
  int dTime = atoi(argv[8]);
for(int i = 0; i < argc; i++){
    printf("%s",argv[i]);
}
}
//   while(threadA || threadB || threadC || threadD ){
//     if(threadA){
//       if(aTime > timeSlice){
//           aTime -= timeSlice;
//           printf("A:%d:%d\n", timeSlice, aTime);
//       }else if(timeSlice > aTime && aTime > 0){
//           printf("A:%d:Done\n", aTime);
//           threadA = false;
//       }
//     }
//     if(threadB){
//       if(bTime > timeSlice){
//           bTime -= timeSlice;
//           printf("B:%d:%d\n", timeSlice, bTime);
//       }else if(timeSlice > aTime && aTime > 0){
//           printf("B:%d:Done\n", bTime);
//           threadB = false;
//       }
//     }
//     if(threadC){
//       if(cTime > timeSlice){
//           cTime -= timeSlice;
//           printf("C:%d:%d\n", timeSlice, cTime);
//       }else if(timeSlice > cTime && cTime > 0){
//           printf("C:%d:Done\n", cTime);
//           threadC = false;
//       }
//     }
//     if(threadD){
//       if(dTime > timeSlice){
//           dTime -= timeSlice;
//           printf("D:%d:%d\n", timeSlice, dTime);
//       }else if(timeSlice > dTime && dTime > 0){
//           printf("D:%d:Done\n", dTime);
//           threadD = false;
//       }
//     }                      
//   }
//   return 0;
// }


bool run(char thread, int time){
    if(time > timeSlice){
        time -= timeSlice;
        printf("%c:%d:%d", thread, timeSlice, time);
        return true;
    }else if(timeSlice > time && time > 0){
        printf("%c:%d:Done", thread, timeSlice-time);
        return false;
    }
}