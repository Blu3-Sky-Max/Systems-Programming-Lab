#include <stdio.h> 

/* 
Euclidean algorithm 

Helps to find the greatest common divisor(gcd)  between two non-negative integer values 

usage: gcc Great_Common_Divisor.c ; ./a.out 
 
*/ 

int main() { 

 int i , j, result; 

printf("Enter two non-negative number: "); 
scanf("%i%i",&i,&j);

while ( j != 0){ 

result = i % j ; 
  i = j;
  j= result;  
} 

 printf("The greatest common  divisor of these numbers is: %d\n", i) ; 



} 
