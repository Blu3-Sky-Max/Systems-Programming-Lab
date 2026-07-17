#include <stdio.h>

/* compute the closest number to the square root of the number given */ 

float absolute_value(float x ){
    if ( x < 0) 
    x=-x; 
    
    return x; 
}   



float Square_Root (float x){

    // the lower epsilon the accurate the answer
    const float epsilon = .000001;
    float guess= 1.000 ; 



    guess= (x/guess + guess ) / 2.0 ; 
    return guess ; 
} 

int main()
{
    float n ; 
    printf("Enter the number you want the square: "); 
    scanf("%f", &n);

// handling nan(not a number): negavtive number 
 if ( n  < 0 ) { 
printf ("Error nan\n");
return false;
                      }
 
    printf("%f\n",Square_Root(n)); 
  
  return true; 
    
    
    
}
