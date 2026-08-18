#define IS_ALPHABETIC(input)  (  ((input) >='A' && (input) <='Z')  OR_Gate ((input) >='a' && (input) <='z') )
#define OR_Gate || 
 
#include <stdio.h> 




int main (){
    
    char m; 
    printf("%s","Enter a char: "); 
    scanf("%c",&m); 
    
    if(IS_ALPHABETIC(m))
    printf("Yes it's an alphabetic \n"); 
    else 
     printf("NO it's not an alphabetic \n"); 

    
    
} 
