#include <stdio.h> 

unsigned int shift (unsigned int values , int n){ 
    
    if (n > 0) // left shift 
    values <<= n;  
     else
     // right shift 
     values >>=-n; 
     
     return values; 
     
     
    
    
    
} 

int main (){
    
    unsigned int w1 = 0177777u , w2=0444u; 
    
    
    printf("%o\t%o\n",shift(w1,5),w1 << 5); 
    printf("%o\t%o\n",shift(w1,-6),w1 >> 6); 
     printf("%o\t%o\n",shift(w2,0),w2 >> 0); 
    
}
