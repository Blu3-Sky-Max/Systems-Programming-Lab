#include <stdio.h>
/* sorting array with pointer */ 

void  Sort( int *  values, const int size){ 
    int tmp; 
    int *outter_ptr=values, *inner_ptr; 
    for(; outter_ptr < values + size; outter_ptr++)
    
    for (inner_ptr=outter_ptr; inner_ptr< values + size; ++inner_ptr )
        
        if ( *outter_ptr > *inner_ptr ){ 
        
             tmp= *outter_ptr ; 
             
             *outter_ptr = *inner_ptr; 
             
             *inner_ptr = tmp; 
    } 
    
    
} 
 
int main()
{
  int arr[10], *printer=arr; 
  
  int array_size=sizeof(arr)/sizeof(arr[0]); 
  
  printf("%s", "Enter your 1-10 number.output will be sorted: "); 
  
  for (int i=0; i < array_size ; i++ )
      scanf("%i",(printer + i)); 
      
      
     Sort(arr,array_size ); 
     printf("\n%s", "Sorted arrary:"); 
     
     for (int i=0; i < array_size ; i++ )
     
     printf("  %i ", *(printer + i)); 
     
     puts(""); 
     
     
     
}
