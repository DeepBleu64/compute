#include<stdio.h>
#include<stdlib.h>
int computation(int a ,int b,char x);
void printusage();
int main(int argc , char *argv[]) {

  int a , b ;
  char x ;
  if(argc != 4 ) {

    printf("Incorrect usage\n");
    printusage();
  }else {
    int arg1 = atoi(argv[1]);
    char arg2 = argv[2][0];
    int arg3 = atoi(argv[3]);
    int result = computation(arg1,arg3,arg2);
    if (result != -1) {
      printf("%d\n",result);
      return 0 ;
    }else {
      printf("Error\n");
      printusage();
      return 1 ;
    }
  }
}
