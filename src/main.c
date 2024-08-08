#include <stdio.h>
#include "convert_expression.h"
#include <stdbool.h>



//functions prototyps

bool computation(double a ,double b,char x,double *result);
void printusage();

int main(int argc , char *argv[]) {

  double arg1  ,arg2   ;
  double result ;
  char arg3 ;
  
  if(argc == 2 ) {

        
    result = input(argv[1]);
    printf("%g\n",result);



     } else if(argc == 4) {

    if(sscanf(argv[1],"%lf" ,&arg1) == 1 && sscanf(argv[2],"%c",&arg3) == 1 && sscanf(argv[3] , "%lf",&arg2) == 1) {

      
      computation(arg1,arg2,arg3,&result);

      printf("%g\n",result);
            

    }

  } else  {

    printusage();

    return 1;

    
  }


  return 0;
      
} 
