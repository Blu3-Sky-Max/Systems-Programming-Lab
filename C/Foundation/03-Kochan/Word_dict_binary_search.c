#include <stdio.h> 
/* binary search of dict
 * note: the Internal_input string has to 
 * in alpha'  order to make the search work. 
 *
 * you can debbug using gdb if lost
 */ 

struct entry { 
    
  char words[20]; 
  char definition[200]; 
    
}; 



int compare_string(const char s1[], const char s2[])
{
    int i=0,answer; 
    
    while ( s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
    i++; 
    
    // compare which one is longer 
    if ( s1[i] < s2 [i])
    
    answer=-1; 
    
    else if ( s1[i] == s2[i])
    
    answer=0; 
    else 
    answer= 1; 
    
    return answer; 
    
}


int lookup ( const char user_input[],struct entry Internal_input[], int size  ){ 
    
    // binary search 
    
    int low=0, mid=0, high=size -1, result; 
    
    while ( low <= high){ 
        
        mid=  (high + low )/2;
        
        result= compare_string(Internal_input[mid].words,user_input); 
        
        // if mid is less than  Internal_input
        if (result == -1)
        low= mid + 1; 
        
        // if mid is greater than Internal_input
        else if ( result == 1)
        high = mid -1; 
        
        else 
        
        return mid; 
    } 
    
    return -1; 
    
    
    
    
} 






int main (){ 
    
    char user_input[20]; 
    int enteries=7, output; 
    
    struct entry Internal_input[7]={ 
        { "abs","anti-lock Braking System in cars" },
        { "apple","The fruit God told adam not to eat and he ate it" },
        { "honey-bee", "a beautiful girl"},
        { "keen", "To be eager"}, 
        { "lexicography", "Lexicography is the study of lexicons" },
        { "stupid", "lacking intelligence, showing poor judgment, or feeling dazed and slow-witted."}, 
        { "usman", "The powerfull man in all the whole building" },
    
}; 
   printf("%s","Enter look_up word: "); 
   scanf("%19s", user_input); 
   output=lookup(user_input,Internal_input,enteries); 
   
   if ( output != -1)
   printf("%s\n", Internal_input[output].definition); 
   else
   printf("The word %s can't be find in your dictionary sir \n", user_input); 


} 


