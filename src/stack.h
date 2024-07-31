#ifndef STACK_H

#define STACK_H

#define MAX 100


extern char op_stack[MAX];
extern char out_stack[MAX];
extern double eval_stack[MAX];

extern int op_pointer;
extern int out_pointer;
extern int eval_pointer;


void push(char *stack_name, char item);
void pop(char *stack_name);

void push_double(double item);
double pop_double();


int should_pop(char c_in , char c_coming);


#endif
