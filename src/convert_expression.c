#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool computation(double a , double b , char x , double *result) ;

enum assoc {

  ASSOC_NONE = 0 ,
  ASSOC_LEFT     ,
  ASSOC_RIGHT    ,
  
};

typedef struct Prece {


  char op ;
  int prec ;
  int assoc;

}Prece;

Prece p[] = {

  '+' , 0 , ASSOC_LEFT  ,
  '-' , 0 , ASSOC_LEFT  ,
  '*' , 1 , ASSOC_LEFT  ,
  '/' , 1 , ASSOC_LEFT  ,
  '^' , 2 , ASSOC_RIGHT ,
  ')' , 2 , ASSOC_NONE  ,
  '(' , 2 , ASSOC_NONE  ,
};


int isdigit(int c) {

  return(c >= '1' && c <= '9' ? 1 : 0) ;


}

int isop(int c) {

  if(c == '+' || c == '*' || c == '/' ||
     c == '^' || c == '-')return 1 ;


  return 0;
}

int *find_pre_asso(char s) {

  int *ele = malloc(2 * sizeof(int));
  
  if(ele == NULL) {
    
    fprintf(stderr,"Failed to allocate memory\n");
    exit(1);
    
  }
  
  int size = sizeof(p) / sizeof(p[0]) ;
  
  int i ;
  for(i = 0 ; i < size ; ++i) {

    if(s == p[i].op) {
      
      ele[0] = p[i].prec ;
      ele[1] = p[i].assoc;

      return ele;

      }
    
  }
  return NULL;
}



void infix_to_postfix(char *s) {
  // 7 + 3 * 4 - 2  
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
      
    }
    
    else if(isop(*s)) {

      if(op_pointer != -1) {

	while(op_pointer != -1 &&
	      should_pop(op_stack[op_pointer],*s)) {

	  push("out_stack",op_stack[op_pointer]);
	  pop("op_stack");
	  
	}
	
      }
      
      push("op_stack",*s);
      
    } else if(isdigit(*s) || *s == '.') {
      
      push("out_stack",*s);
      
    } else if(*s == ' ' && isdigit(*(s + 1)) ||
	      *s == ' ' && isop(*(s + 1))) {

      push("out_stack",'#');
      
    }
   
    s++;

  }
  
  while(op_pointer != -1) {

    push("out_stack",op_stack[op_pointer]);
    pop("op_stack");
    
  }

  push("out_stack",'\0');
  
}

int check_input(char *s) {

  int left_b , right_b ;
  int len = strlen(s);
  left_b = right_b =  0 ;
  bool check_op = false ;
  if(len > MAX) return 0 ;

  if(isop(s[0]) && s[0] != '-' || isop(s[len - 1])) return 0;
     
  while(*s != '\0') {
    
    if(*s == '(')left_b++;

    else if(*s == ')')right_b++;



    if(isop(*s) && check_op && *s != '-') return 0;

    else if(isop(*s)) check_op = true ;
    
    else if(isdigit(*s))check_op = false ;


    

    
    if(*s == ' ' || isdigit(*s) || isop(*s) ||
       *s == '(' || *s == ')' || *s == '.' &&
       isdigit(*(s + 1))  ) {
      
      ++s;
      continue ;
      
      
    }else return 0 ;
  }

  if(left_b != right_b) {

    fprintf(stderr,"You haven't enclosed all brackets\n");

    exit(1);

  }

  
  return 1;
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


char *find_full_digit(char *s) {

  char *output = NULL ;
  int count , i ;
  count = 1;
  i = 0 ;
  while (*s != '#' && isdigit(*s) || *s == '.') {
    
    output = realloc(output,count * sizeof(char)) ;
    output[i++] = *s ;
    count++;
    ++s;

  }
  
  output = realloc(output,count * sizeof(char));
  output[i] = '\0' ;

  return output ;
}

double eval_expression(char *postfix) {


  char *word = NULL;
  double result = 0;

  
  while(*postfix != '\0') {
    

    if(isdigit(*postfix)) {

      word = find_full_digit(postfix);
      postfix += strlen(word);
      push_double(to_double(word));
      free(word);
    }
    

    if(isop(*postfix)) {

      computation(pop_double(),pop_double(),*postfix,&result);

      push_double(result);


      }

      postfix++;      
    }



  return pop_double();
}

char *reformat(char *s) {

  char *output = NULL ;
  int count , i ;
  count = 1 ;
  i = 0 ;
  
  while(*s != '\0') {

    if(*s == ' ' && *(s + 1) == ' ')  {

      ++s;
      continue ;

    } else if(isdigit(*s) && isop(*(s + 1)) ||
	      isop(*s) && isdigit(*(s + 1)))  {

      count += 2 ;
      output = realloc(output,count * sizeof(char));
      output[i++] = *s;
      output[i++] = ' ';
      ++s;


    } else {
      
      output = realloc(output,count * sizeof(char)) ;
      output[i] = *s ;
      ++i;
      ++count;
      ++s;
    }
    
  }
  
  output = realloc(output,count * sizeof(char));
  output[i] = '\0' ;
  
  return output ;
}

double input(char *s) {

  double output = 0;
  char *reformated = NULL ;
  char *str = NULL ;
  
  if(check_input(s)) {

  reformated = reformat(s);

  infix_to_postfix(reformated);

  output = eval_expression(out_stack);
  free(reformated);
  
  }else {

    fprintf(stderr,"Your input contains something that's not permissible\n");
    printf("Avalible operations [+,-,*,/,^,(,)]\n");
    exit(1);
  }
  return output ;
}

