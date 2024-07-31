#include "stack.h"
#include "convert_expression.h"
#include <string.h>

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

  return(find_pre(c_in) < find_pre(c_coming) ? 0 : 1);
}

