
#include <stdio.h>


// convert character to integer; 
int converter_string_to_integer( char input[]){ 
  
  int holder, result=0; 
  for (int i=0; input[i]  >= '0' && input[i] <='9'; i++) {
      
    // you convert input char to integer by input  - '0'(value is 48)
    holder=input[i] - '0'; 
    
    result= result * 10 + holder; 
  } 
    
    return result; 
    
} 

// convert integer to a string
void convert_integer_to_string(int input, char result[]){
    
    int i=0; 
    
     int holder; 
     for (; input != 0 ; i++){ 
         holder= input % 10; 
         // add + 48 makes it a char '0' is 48; 
         result[i]= holder + '0'; 
          input = input /10; 
          
           
} 

 result[i]='\0';
 

 int j=0; char holder2;
 
while ( j < i -1 ){
    
    holder2=result[j];
    
    result[j]=result[i-1];
    
    result[i-1]=holder2;
    j++;
    i--; 
}
    
 
      
        
    
} 

int main()
{
  
  char arr[20]; 
  
  convert_integer_to_string(1234054,arr); 
  
 
  printf ("%s\n",arr);
  printf("%i",converter_string_to_integer ("902")); 
  
} 


        
        
