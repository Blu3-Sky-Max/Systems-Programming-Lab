#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

/* CLI dictonary search and the use of pointer
 * e.g ./a.out Usman 
 * The dark skin man
 */ 

typedef struct { 


  char *name_search; 
  char *__definition; 




}__dictionary_entry; 

 
int __dictionary_search(__dictionary_entry * __input, const char *cli_input, int size  ){ 
     int i=0; 
 while ( __input[i].name_search != NULL   && i < size){  
   if (strcmp(__input[i].name_search, cli_input) == 0){ 
         return i; 
}
     i++; 
} 

  return 0; 
} 





int main (int argc, char * argv[]) { 

 int size=5, __answer_holder;

  __dictionary_entry __dictionary_input[50]= { 
        { "ABS", "Anti-lock Braking System"}, 
	{ "abyss", "a bottomless pit"}, 
	{ "ajar", "a jelly made from seaweed"}, 
	{ "acumen", "mentally sharp; keen"}, 
	{ "Usman", "The dark skin man"}  
 				
};  

 if (argc !=2) { 
  fprintf(stdout,"No word is entered sir or beyond 2 ARGs \n"); 
  exit ( EXIT_FAILURE); 
} 

__answer_holder=__dictionary_search(__dictionary_input, argv[1] ,size);  

 if (__answer_holder !=0) 
 fprintf(stdout, "%s\n", __dictionary_input[__answer_holder].__definition );  
 else 
  fprintf(stdout,"%s can't be found sir \n", argv[1]); 

  




} 
