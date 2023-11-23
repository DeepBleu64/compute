#include<stdio.h>
double computation(double a ,double b,char x);
int isnum(char s);
void printusage();
int main(int argc , char *argv[]) {

  double arg1  ,arg2   ;
  char arg3 ;
  if(argc == 2 ) {

      if(sscanf(argv[1] , "%lf%c%lf" , &arg1,&arg3,&arg2) == 3){
    double result = computation(arg1,arg2,arg3);
    if (result != -1) {
      printf("%lf\n",result);
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

    if(sscanf(argv[1],"%lf" ,&arg1) == 1 && sscanf(argv[2],"%c",&arg3) == 1 && sscanf(argv[3] , "%lf",&arg2) == 1 ){
      
    double result = computation(arg1,arg2,arg3);
    if (result != -1) {
      printf("%lf\n",result);
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


