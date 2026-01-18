#include <stdio.h> 
#include <math.h> 

/* Author: Blu3 Sky 
 * Title: recursive-discrete-math-211  
 * Logic: Base case n<=1 recursive step a+(n-1)+u,  */
int seq(int n){

	int a=5, u=6;
if(n<=1) {
 return  a+(n-1)*u ;// i can just put return 1. just want to show it the base case 
}
else {
 return seq(n-1)+u;
 }


}





int main(){ 
int n;


printf("Enter your nth term i will tell you the number: " ) ;
scanf("%d", &n); 
for (int i=1; i<=n; i++) {
printf("%5d", seq(i));} 
puts(""); 
}
