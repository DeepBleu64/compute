#include "stack.h"
#include "parser.h"
#include <string.h>
#include <stdlib.h>

char op_stack[MAX];
char out_stack[MAX];
double eval_stack[MAX];

int op_pointer  = -1;
int out_pointer = -1;
int eval_pointer = -1;

void push(char *stack_name , char item) {

  if(strcmp(stack_name,"op_stack") == 0) {

    if(op_pointer + 1 == MAX - 1)return;

    op_stack[++op_pointer] = item ;

  }else if(strcmp(stack_name,"out_stack") == 0) {

    if(out_pointer + 1 == MAX - 1)return ;

    out_stack[++out_pointer] = item;
    

  }
  
}


void pop(char *stack_name) {

  if(strcmp(stack_name,"op_stack") == 0) {

    if(op_pointer == -1)return;

    op_stack[--op_pointer] ;

  }else if(strcmp(stack_name,"out_stack") == 0) {

    if(out_pointer == -1)return ;

    out_stack[--out_pointer];
    

  }
  
}

void push_double(double item) {

  if(eval_pointer + 1 == MAX) return ;


  eval_stack[++eval_pointer] = item ;
}



double pop_double() {

  if(eval_pointer == -1)return 0.0 ;

  return eval_stack[eval_pointer--];

}

int should_pop(char c_in , char c_coming) {

  int *arr1 = find_pre_asso(c_in);
  int *arr2 = find_pre_asso(c_coming);

  /* Should not pop if precedence of scanned op is greater than precedence of op in stack || op scanned  is  right-associative  ||
   op in stack is non-associative*/ 
  
  if(arr1[0] < arr2[0] || arr2[1] == 2 ||
     arr1[1] == 0) {

    free(arr1);
    free(arr2);

    return 0;

  } 

  free(arr1);
  free(arr2);

  return 1;

}

