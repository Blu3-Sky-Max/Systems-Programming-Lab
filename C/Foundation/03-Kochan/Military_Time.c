#include <stdio.h> 


struct Time{ 
    int hour,
    min,
    sec; 
}; 

struct Time nextime(struct Time input){ 
    ++input.sec; 
    
    if ( input.sec == 60 ){ 
      input.sec=0; 
      ++input.min; 
      
      if (input.min == 60){ 
          input.min=0; 
          input.hour++; 
      
         
         if (input.hour == 24)
          input.hour=0; 
          }
} 
 return input;



 
} ; 

int main (){ 
    
 struct Time time_now,Updated_time;  
 
 printf ("Enter your Exact Time (sec:min:hour) "); 
 scanf ("%d : %d : %d",&time_now.sec, &time_now.min, &time_now.hour); 
  
 
    Updated_time=nextime(time_now); 
    
    printf("Current Time: %.2i:%.2i:%.2i \n",Updated_time.sec,Updated_time.min,Updated_time.hour); 

    
} 
