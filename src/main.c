#include<stdio.h>
#include <stdbool.h>
#define MAX_INT 2147483647
//functions prototyps 
bool computation(double a ,double b,char x,double *result);
int parsevalue(double y);
void printusage();
int main(int argc , char *argv[]) {

  double arg1  ,arg2   ;
  double result ;
  int trunc ;
  char arg3 ;
  if(argc == 2 ) {

    if(sscanf(argv[1] , "%lf%c%lf" , &arg1,&arg3,&arg2) == 3){
      if (computation(arg1,arg2,arg3,&result)) {
       if(parsevalue(result) || result > MAX_INT) {
      printf("%lf\n",result);
       }else{
      trunc = result ;
      printf("%d\n",trunc);
	 
      }
    }else {
      printf("Error\n");
      printusage();
      return 1 ;
    }
    
    } else{
      printf("Error\n");
      printusage();
      return 1;
       }
     }else if(argc == 4) {

    if(sscanf(argv[1],"%lf" ,&arg1) == 1 && sscanf(argv[2],"%c",&arg3) == 1 && sscanf(argv[3] , "%lf",&arg2) == 1 ){
      
      if (computation(arg1,arg2,arg3,&result)) {
	if(parsevalue(result) || result > MAX_INT){
       printf("%lf\n",result);
      }else {
	 trunc = result ;
      printf("%d\n",trunc);
      }
    }else {
      printf("Error\n");
      printusage();
      return 1 ;
    }

    
      }else{
	printusage();
	return 0 ;
      }

  }else{
    printf("Incorrect usage\n");
    printusage();
  }

  

} 
