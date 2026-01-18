
#include <stdio.h> 
#include <math.h>



/* Author: Blu3 Sky 
 * Title: recursive-discrete-math-211  
 * Logic: Base case n<=0 recursive step 2 *m(n-1) +3,  */
long long  m(int n){
   long  long a= 3;
    
    if(n<=0){
        return a; 
    }
    else {
        return 2 *m(n-1) +3; 
    }
}

int main()
{
   long long n;
    printf("tell me the loop you want for the recursive: ");
    scanf("%lld", &n);
    
    printf("%lld\n", m(n));

    
}

