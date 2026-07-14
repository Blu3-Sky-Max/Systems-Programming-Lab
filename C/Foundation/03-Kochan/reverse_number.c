#include <stdio.h>
/* this program helps in reverse number e.g 1234 to 4321 */

int main()
{
     int i,tmp; 
     
      printf("Enter the number you want in reverse: "); 
      scanf ("%i",&i); 
     
     while ( i != 0 ){ 
     tmp= i % 10;
     i=i/10; 

       printf("%i", tmp); 
     } 
  puts("");
}

