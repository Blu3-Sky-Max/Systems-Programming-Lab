#include <stdio.h> 
#include <math.h> 

// the quardatric formular 



int Power_handler(int x, int n){
     
    if ( n <=0)
    return 1; 
    else 
    return x * Power_handler(x,n-1); 
        
} 

void squareRoot(int a, int b, int c){
    double x1, x2; 
      x1 = ( -b + sqrt( Power_handler(b,2) - 4 * a * b)) / (2*a) ; 
      x2 = ( -b - sqrt( Power_handler(b,2) - 4 * a * b)) / (2*a) ; 
      printf( "x1= %f and x2 = %f  \n",x1,x2);
} 

int main(){ 
    
    
    int a,b,c; 
    printf("Enter your a , b and c: ");
    scanf ("%d %d %d",&a,&b,&c); 
    
    if ( Power_handler(b,2) - (4 * a * c) < 0 )
    printf ("The root is imaginery Sir\n");  
    else 
     squareRoot(a,b,c); 
    
}   
