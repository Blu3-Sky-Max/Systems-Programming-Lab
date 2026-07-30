#include <stdio.h> 
#include <stdbool.h> 

// Dictionary-Lookup.c — struct-based word lookup using linear search

struct entry { 
    
    char word[12]; 
    char definition[200]; 

}; 



bool Check_equal_string(const char s1[], const char s2[]){ 
    int i=0; 
     bool is_equal; 
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i++ ;
    // you can also say " if ( s1[i] == s2 [i]) ; still work perfectly"  
     if ( s1[i] == '\0' && s2 [i] == '\0')
     is_equal = true;  
     else 
     is_equal = false;
     
     return is_equal; 
} 

int Look_up(const struct entry real_word_dict[], const char user_input[], const int enteries ){ 
    int i=0; 
    for (; i < enteries; i++) 
    if  ( Check_equal_string(real_word_dict[i].word, user_input) ) 
    return i; 

    return -1; 
    
} 

int main (){ 
    char user_input[20]; 
     int enteries=3; 
     int output=0; 
struct entry real_word_dict[3]= {  { "usman" , "The most powerful man in the word"}, 
                                { "hollow", "to bless consecrate" },
                                     { "more", "more is written less in all gnu books" } 
    
} ; 

  printf("Enter the words you want to search for: "); 
  scanf("%s",user_input); 
  output = Look_up(real_word_dict,user_input,enteries); 
  
  if (output != -1)
   printf("%s\n", real_word_dict[output].definition); 
   else
   printf("The word %s can't be find sir \n", user_input); 
    
    
} 
