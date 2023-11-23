#include <stdio.h>
#define MAX 100

int power(int base , int p );

int computation(int a , int b , char x) {

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
    return (double)a/b ;
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

int isnum (char a) {


  if(a >= '1' &&  a <= '9') {
    return 1;
  }else{
    return 0 ;
  }
}
