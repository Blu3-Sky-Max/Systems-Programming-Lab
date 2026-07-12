#include <stdio.h>


//  Handle keyed input and return it in words e.g 42 to four two 

void funky(int j){
    // stack(LIFO) happens here like 1234 will be stack like this 1234,123,12 and  1 
 if ( j >= 10 ){ 
     funky(j / 10); 
 } 
  
 // the one is the first to come out here which it will return the 0.1 and j will print one  
 switch (j % 10 ){ 
      case 1: 
      printf ("one ");
      break ; 
      case 2: 
      printf ("two ") ;
      break; 
      case 3: 
      printf ("three "); 
      break; 
      case 4: 
      printf ("four ");
      break; 
      case 5: 
      printf ("five ");
      break;
      case 6: 
      printf ("six ");
      break; 
      case 7:
      printf ("seven ");
      break;
      case 8: 
      printf ("eight ");
      break;
      case 9: 
      printf("nine ");
      break;
      case 0: 
      printf("zero ");
      break; 
      
     
      
    } 
 
        

}

int main()
{
     int x;  
    printf ("Enter your number: "); 
    scanf("%d", &x);
    
    if ( x < 0){ 
    printf("The number can't be negative");
    } 
    funky(x); 
   puts(""); 
    
}

