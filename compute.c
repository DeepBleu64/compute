#include <stdio.h>
#include <stdbool.h>
#define MAX 100

double power(double base , double p );

bool computation(double a , double b , char x , double *result) {

  switch(x) {
  case '+':
      *result = a + b ;
      return true ;
  case '-':
     *result =  a - b ;
      return true ;
  case 'x':
      *result =  a * b ;
      return true ;
  case '/':
    if (b == 0 ) {
      return false;
    }else{
     *result = a/b ;
     return true ;
    }
  case '^':
     *result =  power(a,b) ;
     return true ; 
   default:
    return false ;

  }
}


void printusage(){


  printf("Usage eg: Val1 operator Val2\n");
  printf("Supported operators [+,-,x,/,^]\n");
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
