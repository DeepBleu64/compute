#include <stdio.h>
#define MAX 100

int power(int base , int p );

double computation(double a , double b , char x) {

  switch(x) {
  case '+':
    return a + b ;
  case '-':
    return a - b ;
  case 'x':
    return a * b ;
  case '/':
    if (b == 0 ) {
      return -1;
    }else{
    return a/b ;
    }
  case '^':
    return power(a,b) ;
   default:
    return -1 ;

  }
  return -1 ;
}


void printusage(){


  printf("Usage eg: Val1 operator Val2\n");
  printf("Supported operators [+,-,x,/,^]\n");
}


int power(int base , int p ){

  int i ;
  int result = 1 ;
  for(i = 0 ; i < p ; i++) {

    result *= base;

  }
  return result ;

}


int parsevalue(double x) {

  char s[MAX];
  int breakouter = 0 ;

  sprintf(s , "%f",x) ;

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
