#include <stdio.h> 
#include <stdbool.h> 

//  helps to find if a number is prime number or not 
int main () {

  bool isprime=true; 
int i ; 
printf ("Enter your  number: " ) ; 
scanf("%i", &i);

for (int j=2; j<i; j++){  
 
  if ( i % j == 0 ) 
   isprime=false ; 
 } 

  if  ( isprime == true ) { 
  printf("%i is a prime number  ", i);
 } 

else if  ( isprime == false ) { 
printf ("The number is not a prime number" ) ; 
} 
 else 
 printf("The character is unkown" ) ;  
 

 
puts (""); 



 }
