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
    return (double)a/b ;
  case '^':
     int result = power(a,b);
     return result ;
   

  }
  return -1 ;
}


void printusage(){


  printf("Usage eg: Val1 oprand Val1\n");
  printf("Supported oprandnds [+,-,x,/,^]\n");
}


int power(int base , int p ){

  int i ;
  int result = 1 ;
  for(i = 0 ; i < p ; i++) {

    result *= base;

  }
  return result ;

}
