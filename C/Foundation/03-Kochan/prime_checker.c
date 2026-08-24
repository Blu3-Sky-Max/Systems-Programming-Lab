
#include <stdio.h>
#include <stdbool.h>  

// prime chcecker of values 


int __prime(int _user_input){
     bool holder=true ;
     
    if (_user_input <= 1){ 
      return -1; 
    } 
    
    
    else 
    for (int i=2; i < _user_input; i++)
        if (_user_input % i == 0) 
            holder=false; 
            
            
            return holder; 
    
    
    
}

int main()
{
    int User;  
    printf("%s","Enter a number: ");
    scanf("%i", &User);
    
    if ( __prime(User) == true )
      printf("it's a prime sir \n "); 
      else 
      
      printf("it's not a prime sir \n");



   puts(""); 
    
}
