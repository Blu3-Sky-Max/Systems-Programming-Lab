#include <stdio.h> 

unsigned int OR_operation (int user_input){ 
	
    for (int i=0; i<5; i++) 
	    user_input |=i; 


    return user_input; 



} 	

unsigned int  And_operation  (int user_input) { 
    
	for (int i=0; i<5; i++) 
		user_input &=i; 


	return user_input; 

} 
unsigned int Xor_operation (int user_input) { 

   for (int i=0; i < 5; i++)
	   user_input ^=i;

   return user_input; 


} 


int main () { 
    
 // output are coming back in octals not decimal 
     printf("%o\n", OR_operation(0231)); 

     printf("%o\n", And_operation(0231)); 

    printf("%o\n", Xor_operation(0231)); 










} 
