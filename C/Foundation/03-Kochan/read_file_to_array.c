#include <stdio.h> 
/* simple analogy of reading 
 * from a file and copy it  into  
 * an array and printing it out in terminal
 */  

FILE * __Opener; 

int main () { 

__Opener= fopen("/home/blue/input_by_usman" , "r") ; 


int _holder[100], c, i,j;

i=j=0;  



if (__Opener == NULL ){
   perror("ERROR"); 
   return -1 ; 

} 


while ( ( c=getc(__Opener)) != EOF &&  i < 100){ 

       _holder[i]=c; 

   i++;


} 


for (; j <i; j++) { 
  printf("%c", _holder[j]); 

} 



} 
