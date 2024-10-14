#include "stack.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





Prece p[] = {

  '+' , 0 , ASSOC_LEFT  ,
  '-' , 0 , ASSOC_LEFT  ,
  '*' , 1 , ASSOC_LEFT  ,
  '/' , 1 , ASSOC_LEFT  ,
  'u' , 2 , ASSOC_RIGHT , // u is for unary-minus 
  '^' , 3 , ASSOC_RIGHT ,
  ')' , 3 , ASSOC_NONE  ,
  '(' , 3 , ASSOC_NONE  ,
};




int *find_pre_asso(char s) {

  /* returns an array containing precedence + associativity for a given operator*/
  
  int *ele = malloc(2 * sizeof(int));
  
  if(ele == NULL) {
    
    fprintf(stderr,"Failed to allocate memory of length 4 for int array\n");
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



char *find_full_digit(char *s) {

  char *output = NULL ;
  int count , i ;
  count = 1;
  i = 0 ;
  
  while (*s != '#' && ISDIGIT(*s) || *s == '.') {
    
    output = realloc(output,count * sizeof(char)) ;
    
    if(output == NULL) {
      
      fprintf(stderr,"Failed to allocate memory for an additional byte of char\n");
      exit(1);

      
    }
    
    output[i++] = *s ;
    count++;
    ++s;

  }
  
  output = realloc(output,count * sizeof(char));

  if(output == NULL) {
      
      fprintf(stderr,"Failed to allocate memory for an additional byte of char for a null-byte\n");
      exit(1);

      
    }
  
  output[i] = '\0' ;

  return output ;
}


double apply_unary(double a) {


  return -1 * a ;
  
}

char  *deal_with_op(char *s , char *start) {

  char ins ;
  
  int pos = s - start ;

  
  switch(*s) {

    /* Different unary expressions , -AB , -(A+B) , b+-A , -A^B */

    
  case '-':



    
    if(pos == 0 && *(s + 1) == '(' ||
       pos > 0 && *(s + 1) == '(' &&
       pos > 0 && *(s - 1) == ')') ins = 'u';     /* Apply unary minus on the whole expression  in the case of -(A+B) for instance */

    else if(pos > 0  && ISOP(*(s - 1)) || /* Otherwise if a unary minus is found that's not in the form of -(A+B) apply unary minus on that term only */
	    pos > 0 && *(s - 1) == '(' ||
	    pos == 0 && ISDIGIT(*(s + 1))) {

      char *word = find_full_digit(++s);
      
      s += strlen(word);


      if(*s == '^') { /* if a unary minus followed by exponent e.g: -A^B , apply unary minus on the whole operation , meaning it would be in
			 eval stack AB^u , intead of AU^B , meaning it would be -(A)^B  */ 

	ins = 'u' ;

	free(word);
	
	break;

      }
      
      for(int i = 0; word[i] != '\0'; i++)push("out_stack",word[i]);


      push("out_stack",'u');


      


      return  word;
      
    }

    
    else ins = '-' ;

    break;
    

   default :

    ins = *s;


    
  }

    if(op_pointer != -1) {
      
	while(op_pointer != -1 &&
	      should_pop(op_stack[op_pointer],ins)) {

	  push("out_stack",op_stack[op_pointer]);
	  pop("op_stack");
	  
	}


      }
  
        push("op_stack",ins);

	return NULL ;
}





int check_input(char *s) {

  int brackets,len;
  brackets =  0 ;

  
  if(s == NULL || (len = strlen(s)) > MAX
     || len == 0) return 0;
    
  
  if(ISOP(s[0]) && s[0] != '-' || ISOP(s[len - 1])) return 0;
     
  while(*s != '\0') {
    
    if(*s == '(')brackets++;

    else if(*s == ')')brackets--;



    if(ISOP(*s) && ISOP(*(s + 1)) &&
       *(s + 1) != '-' || ISOP(*s) && *(s + 1) == ')' ) return 0;



    

    
    if(ISDIGIT(*s) || ISOP(*s) ||
        *s == '(' || *s == ')' || *s == '.' &&
        ISDIGIT(*(s + 1))  ) {
      
      ++s;

      
      
    }else return 0 ;
    
  }

  if(brackets != 0) {

    fprintf(stderr,"You haven't enclosed all brackets\n");

    exit(1);

  }


  
  return 1;
}




