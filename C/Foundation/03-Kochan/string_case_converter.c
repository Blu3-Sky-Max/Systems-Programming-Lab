#include <stdio.h>
/* convert small lettter to capital letter
   second func convert cap to small letter
   */ 
   
void getter ( char user_input[], const int size){ 
    
    char character; int i=0;  
    
    do 
    { 
        character=getchar(); 
        user_input[i]=character;
        i++; 
        // the minus one is for "\0" to  reserve/control overflowing 
    } while ( i < size - 1  && character != '\n');
 
    user_input[i]= '\0'; 
        
}        

void convert_small_letter_cap (char user_input[]){ 
    
    for (int i=0; user_input[i] != '\0'; i++)
    
        if ( user_input[i] >='a' && user_input[i] <='z')
        
           user_input[i] = user_input[i] - 32 ; 
    
    
} 
// convert capital to small letter 
void convert_cap_letter_small (char user_input_cap[]){ 
    for (int i=0; user_input_cap[i] != '\0'; i++)
    
        if ( user_input_cap[i] >='A' && user_input_cap[i] <='Z')
        
           user_input_cap[i] = user_input_cap[i]  + 32 ; 
    
    

} 

int main()
{ 
    char user_input[200]; 
    char cap_input[200]; 
    
    printf("Enter your string: ");
               getter(user_input,sizeof(user_input));
    
    convert_small_letter_cap(user_input);
    
    printf("Enter your string in capital: "); 
        getter(cap_input,sizeof(cap_input)); 
    
    convert_cap_letter_small(cap_input); 
    
    printf("%s\n", user_input); 
     printf("%s\n", cap_input);
    
    
    
}
