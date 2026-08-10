#include <stdio.h> 

 // sorting integer without an array  
 
void Sort3(int *input1, int*input2, int * input3){ 
     int holder;  
     
  
   if ( *input1 > *input2){ 
        holder= *input2; 
        *input2=*input1;
        *input1=holder; 
        
   } 
   
   
   if ( *input2 > *input3){ 
   holder=*input3;
   *input3=*input2;
   *input2=holder; 
   
   } 

  if ( *input1 > *input2){ 
        holder= *input2; 
        *input2=*input1;
        *input1=holder; 
   } 
   
     
    
    
    
    
} 


int main (){ 
    
  
  int x,y,z; 
  printf("%s", "Enter your your number: "); 
  scanf("%i %i %i", &x,&y,&z); 
    
    Sort3(&x,&y,&z); 
    
    printf("sorted integer: %i %i %i", x,y,z); 
    
    
} 
