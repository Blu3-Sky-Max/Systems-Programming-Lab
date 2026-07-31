#include <stdio.h>


// convert character to interger; 
int converter_string_to_interger( char input[]){ 
  
  int holder, result=0; 
  for (int i=0; input[i]  >= '0' && input[i] <='9'; i++) {
      
    // you conver input char to interger by input  - '0'(value is 48)
    holder=input[i] - '0'; 
    
    result= result * 10 + holder; 
  } 
    
    return result; 
    
} 

// convert interget to a string
void convert_interger_to_string(int input, char result[]){
    
    int i=0; 
    
     int holder; 
     for (; input != 0 ; i++){ 
         holder= input % 10; 
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
  
  char arr[4]; 
  
  convert_interger_to_string(123454,arr); 
  
 
  printf ("%s\n",arr);
  printf("%i\n",converter_string_to_interger ("902")); 
  
} 


        
        
