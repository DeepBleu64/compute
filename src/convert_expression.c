#include "stack.h"
#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool computation(double a , double b , char x , double *result) ;


void infix_to_postfix(char *s) {
  // 7 + 3 * 4 - 2

  char *start = s ;

  char *word = NULL;
  
  while(*s != '\0') {

    
    if(*s == '(') {

      push("op_stack",'(');
    }

    else if(*s == ')') {

      while(op_stack[op_pointer] != '(') {

	push("out_stack",op_stack[op_pointer]);
	pop("op_stack");
	
	
      }
      
      pop("op_stack");
      push("out_stack",'#');
    }

    else if(ISOP(*s))  {

     word =  deal_with_op(s,start);
     
     if(word != NULL) { 

     s += strlen(word) ;
     free(word);
     word = NULL ;
     
    }
      


    
    } else if(ISDIGIT(*s) || *s == '.') {
      
      push("out_stack",*s);
      
    } if(ISDIGIT(*s) && ISOP(*(s + 1)) ||
	 ISOP(*s) && ISDIGIT(*(s + 1))) {

      push("out_stack",'#');
      
    }
   
    s++;

  }
  
  while(op_pointer != STACK_BOTTOM) {

    push("out_stack",op_stack[op_pointer]);
    pop("op_stack");
    
  }

  push("out_stack",'\0');
  
}


double to_double(char *s) {

  double non_fractional , fractional , divisor ;
  non_fractional = fractional = 0 ;
  divisor = 1;

  while(*s != '\0') {

    if(*s == '.') {



      while(*(++s) != '\0') {
	
      fractional = fractional * 10 + (*s - '0') ;
      divisor *= 10 ;

      if(*(s + 1) == '\0')break;

      
      }
      
    } else {

    non_fractional = non_fractional * 10 + (*s - '0') ;
    
    }
    
    ++s;

  }


  return non_fractional + fractional / divisor ;
}




double eval_expression(char *postfix) {


  char *word = NULL;
  double result = 0;

  
  while(*postfix != '\0') {
    

    if(ISDIGIT(*postfix)) {

      word = find_full_digit(postfix);
      postfix += strlen(word);
      push_double(to_double(word));
      free(word);
    }


    
    if(*postfix == 'u') push_double(apply_unary(pop_double()));


      
      
    

    if(ISOP(*postfix)) {

      computation(pop_double(),pop_double(),*postfix,&result);

      push_double(result);


      }

      postfix++;      
    }


  /* By the end of the evaluation the stack must contain only one or two elements  */

  if(eval_pointer == 1) return pop_double() + pop_double(); /* At times in expressions that contain unary minus there would be two elements on the stack
							       one of which is unary minus oprand so the result is their addtion */ 



  
  return pop_double(); /* In normal cases the result would be at the top of stack */
}

char *reformat(char *s) {

  char *output = NULL ;
  int count , i ;
  count = 1 ;
  i = 0 ;
  
  while(*s != '\0') {

    if(*s == ' ')  {

      ++s;
      continue ;



    } else if(ISDIGIT(*s) || ISOP(*s) || *s == '(' || *s == ')' ||
	      *s == '.') {
      
           
      if((output = realloc(output,count * sizeof(char))) ==  NULL) {
      
      fprintf(stderr,"Failed to allocate memory for  additional bytes of char of length: ");
      printf("%dB\n",count);
      exit(1);

      
    }
      output[i] = *s ;
      ++i;
      ++count;
      ++s;
      
    } else {

      
      free(output);
      
      return NULL ;

    }
    
  }
  


  if((output = realloc(output, count * sizeof(char))) == NULL) {
      
      fprintf(stderr,"Failed to allocate memory for an additional byte of char for null-byte  length: ");
      printf("%d\n",count);
      exit(1);

      
    }
  
  output[i] = '\0' ;
  
  return output ;
}



double input(char *s) {

  double output = 0;
  char *reformated = NULL ;

  
  reformated = reformat(s);
  if(check_input(reformated)) {

    
 //   printf("%s\n",reformated);
  
  
  infix_to_postfix(reformated);
  //  printf("%s\n",out_stack);
  output = eval_expression(out_stack);
  free(reformated);
  
  }else {

    fprintf(stderr,"Your input contains something that's not permissible\n");
    printf("Avalible operations [+,-,*,/,^,(,)]\n");
    exit(1);
    
  }
  
  return output ;
}

