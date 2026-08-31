#include <stdio.h>

/* a simple sample of union and enum in
 * a struct and how it  been use 
 */ 

#define   table_size   3 

typedef enum{ INTEGER, FLOATING , CHARACTER}Symbol_type; 


typedef struct { 
    
    char *name; 
    Symbol_type type;
    
    union {
        int __INTEG;
        
        float __FLOAT;
        
        char __CHAT;
    }data; 
    
    
} table[table_size];




int main (){ 
    
 table usman={  { "Marcus", INTEGER, .data.__INTEG=50},
                { "Usman", CHARACTER  , .data.__CHAT='Y'}, 
                 { "Lady_boy", FLOATING, .data.__FLOAT=20.45}
 };  

   for (int i=0; i< table_size; i++){ 
   fprintf(stdout,"%s ", usman[i].name);  

    switch(usman[i].type){
	case INTEGER:
		 fprintf(stdout,"%i\n",  usman[i].data.__INTEG);
	break;

	case FLOATING:
                 fprintf(stdout, "%f\n", usman[i].data.__FLOAT); 
	break; 
	case CHARACTER: 
 		fprintf(stdout, "%c\n", usman[i].data.__CHAT); 
	break; 

	default: 
  	fprintf(stdout, "Unkown type %i\n", usman[i].type) ; 
	break; 




} 
}
} 
