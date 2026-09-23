#include <stdio.h> 
#include <stdlib.h> 

/* Using preproccessor step for debugging 
 */ 


int process (int p1, int p2){ 
 int result; 
#ifdef DEBUG 
fprintf(stdout, "processing(%i %i)\n", p1, p2); 
#endif
  result = p1 * p2; 

#ifdef DEBUG
fprintf(stderr, "return %i\n", result); 

#endif

return result ;

} 



int main ( int __argc, char * __argv[]){ 

int input_one, input_two; 

 if (__argc > 1) 
  input_one=atoi(__argv[1]);
 if (__argc == 3)
  input_two=atoi(__argv[2]); 
 
#ifdef DEBUG

fprintf(stderr, "Argument count %i\n", __argc - 1); 


 fprintf(stdout, "First: %i Second: %i\n", input_one,input_two) ; 

#endif  

 fprintf(stdout, "%i\n", process(input_one, input_two)); 






}  
