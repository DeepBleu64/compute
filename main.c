#include<stdio.h>
int computation(int a ,int b,char x);
int isnum(char s);
void printusage();
int main(int argc , char *argv[]) {

  int arg1  ,arg2   ;
  char arg3 ;
  if(argc == 2 ) {

      if(sscanf(argv[1] , "%d%c%d" , &arg1,&arg3,&arg2) == 3){
    int result = computation(arg1,arg2,arg3);
    if (result != -1) {
      printf("%d\n",result);
      return 0 ;
    }else {
      printf("Error\n");
      printusage();
      return 1 ;
    }

    
      }else{
	printusage();
	return 0 ;
      }

    printf("Incorrect usage\n");
    printusage();
  }else if(argc == 4) {

    if(sscanf(argv[1],"%d" ,&arg1) == 1 && sscanf(argv[2],"%c",&arg3) == 1 && sscanf(argv[3] , "%d",&arg2) ==1 ){
      
    int result = computation(arg1,arg2,arg3);
    if (result != -1) {
      printf("%d\n",result);
      return 0 ;
    }else {
      printf("Error\n");
      printusage();
      return 1 ;
    }

    
      }else{
	printusage();
	return 0 ;
      }

    printf("Incorrect usage\n");
    printusage();
  }else{
    printf("Incorrect usage\n");
    printusage();
  }

  

} 


