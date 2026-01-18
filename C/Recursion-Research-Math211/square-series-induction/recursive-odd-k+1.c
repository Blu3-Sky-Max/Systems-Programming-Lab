#include <stdio.h>
#include <math.h> 


/* Author: Blu3 Sky 
 * Title: recursive-discrete-math-211  
 * Logic: Base case a=1 recursive step (a-1)+(2*a-1),  */
int r(int a){
    if(a == 1){ 
        return 1;
}
else {
    return r(a-1) + (2*a-1);
}
}
int main()
{
    int k; 
    
    printf("Enter your number: ");
    scanf("%d",&k);
    printf("%d\n", r(k));
}                               

