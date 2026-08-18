#define same 1

#include <stdio.h> 

#define MAX(x,y,z)   ((x >  y  && x > z )? x :((x == y  && x == z)? same:(y > z  && y >= x)? y : z)) 

int main()
{
    int l, m,n,  result;
     
 printf("%s", "Enter three number: ");
 scanf("%i %i %i",&l ,&m, &n);
 
  result = MAX(l,m,n); 
  
  if (result == same )
  printf("They are the same\n"); 
  else
  
  printf("%i is the max value\n ", result);  
}
