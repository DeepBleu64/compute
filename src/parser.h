#ifndef PARSER_H

#define PARSER_H

#define ISOP(c) ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '^' || (c) == '/' )

#define ISDIGIT(c) ((c) >= '0' && (c) <= '9')


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





int *find_pre_asso(char s) ;


char *find_full_digit(char *s);


char *deal_with_op(char *s, char *start);
double apply_unary(double a);


int check_input(char *s) ;





#endif 
