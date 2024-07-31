#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 100 /* Maximum buffer size change as needed if you wish to parse  numbers whose digits > 100 */ 

//double power(double base , double p );

int Check_num_digits(double x) ;
bool computation(double a , double b , char x , double *result) {

  switch(x) {
  case '+':
      *result = a + b ;
      return true ;
  case '-':
     *result =  a - b ;
      return true ;
  case '*':
      *result =  a * b ;
      return true ;
  case '/':
    if (b == 0 ) {
      
      fprintf(stderr,"Can't divide by zero\n");
      exit(1);
      
    } else {
     *result = a/b ;
     return true ;
     
    }
  case '^':
     *result =  pow(a,b);
     return true ;
     
   default:

     fprintf(stderr,"Incorrect operator\n");
     exit(1);
     

  }
  
}


void printusage(){


  printf("Usage eg: Val1 operator Val2\n");
  printf("Supported operators [+,-,*,/,^]\n");
  
}


double power(double base , double p ){

  int i ;
  double result = 1 ;
  for(i = 0 ; i < p ; i++) {

    result *= base;

  }
  return result ;

}

int parsevalue(double x) {

  /* Prevents bufferoverflow */
  if(Check_num_digits(x))return 0;

  char s[MAX];
  int breakouter = 0 ;

  sprintf(s,"%f",x) ;

  for(int i = 0 ; s[i] != '\0' && !breakouter ; i++) {

    if(s[i] == '.') {
      breakouter = 1 ;
      for(int j = i+1 ; s[j] != '\0' ; j++) {

	if(s[j] != '0') {

	  return 1;
	}

      }
    }

  }
  
  return 0 ;

}

int Check_num_digits(double x) {

  int i ;
  int count = 0 ;                      
  for (i = 0 ; i < x ; i++) {
    count++ ;
    if(count >= 99) {
      return 1 ;

    }
  }
  return 0 ;
}
