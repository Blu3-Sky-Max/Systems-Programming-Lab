#include <stdio.h>
#include <stdbool.h> 
// counting the number of words in sentences; 

bool alpha(char string){ 
    if (  ( string >= 'a' && string <='z') || (string >='A'  && string <='Z') ) 
        
        return true; 
        else
        return false;
        
    } 
    
int number_words(char string[]){ 
    int count=0; 
    bool looking_forward=true; 
    
    for (int i =0; string[i] !='\0'; i++)
    
       if (alpha(string[i])){
           
           if (looking_forward){
               count++; 
           looking_forward = false; 
           } 
       } 
    else 
            looking_forward=true; 
    return count; 
    
}  
int main()
{
    char words[]= "Well, here we go!  "; 
     char words1[]= "Well, here we go again! sitting on a chair  "; 
    
    printf("%s    number words: %i\n",words,number_words(words)); 
    printf("%s    number  words: %i\n",words1,number_words(words1)); 

}
