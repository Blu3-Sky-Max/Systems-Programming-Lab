#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/* take input from the cli and check 
 * if the argv[1] is in the __dispatch_table
 * then bring the definition out in the terminal
 */ 

typedef struct { 

     char *name; 
     char *definition; 


} __helper; 

int check_string(__helper *checker, char **argv, const int size) { 
   int counter=0; 
	while ( counter < size && argv != NULL ){  
		 if (strcmp(checker[counter].name, *argv) == 0)  
                        break;
  counter++;		 
     } 

   return counter; 

} 




int main (int __argc, char * __argv[]){ 
  int holder; 

__helper  __dispatch_table[5]= { 
	   { "eat", "eat is to put food into your mouth, chew it, and swallow it for nourishment"}, 
	   { "walk", " to move forward on foot by putting one foot in front of the other at a moderate speed"}, 
	   { "sit", "to rest your body with your weight supported on your buttocks or thighs, typically on a chair, stool, or the ground"}, 
	    { "watch", "to observe attentively or a portable timepiece"}, 
	     { "pray", "to speak to God or a god to give thanks or ask for help"} 


};  

 if ( __argc != 2  ){  
	fprintf(stdout,"Sir/Ma, Argument must be two\n");
       exit (40); 
       }        

 if ( (holder=check_string(__dispatch_table, &__argv[1], 5)) != 5) 
	fprintf(stdout, "%s\n",__dispatch_table[holder].definition); 
	else
	fprintf(stderr, "Couldn't find the meaning in the dictionary\n"); 




} 	
