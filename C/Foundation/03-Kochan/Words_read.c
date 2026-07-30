#include <stdio.h>
#include <stdbool.h> 
/*  counting the number of words in sentences
 *   Note: to you have to press enter twice to make 
 *  the enter work well; 
 */ 

//  check the values of user input if it's between range 
bool alpha(char string){ 
    if (  ( string >= 'a' && string <='z') || (string >='A'  && string <='Z') ||  (string >= '0' 
      && string <= '9')) 
        
        return true; 
        else
        return false;
        
    }
// this take the  user input inside 
void read_input(char buffer[]){
 int i=0;

    char character;
  do {
    character=getchar();
     
     buffer[i]=character;
     ++i;

// getchar end sentence with '\n' and char end with '\0'
  } while( character != '\n');
  // repleace the '\n' to '\0'
  buffer[i-1]='\0';

}

 // this func count the number of string    
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
    int counter_words=0; 
    bool end_of_text = false; 
    char input[200]; 
    
    printf("%s","Enter your Sentences (when you're done you can press enter/return):  "); 
    
    
    while (!end_of_text){ 
        
        read_input(input); 
        
        if (input[0] == '\0' ) 
        
        end_of_text = true;
        else 
        counter_words += number_words(input); 
    } 
        
        printf("\nthere are %i words in the text above \n\a",counter_words); 
    
    
}
