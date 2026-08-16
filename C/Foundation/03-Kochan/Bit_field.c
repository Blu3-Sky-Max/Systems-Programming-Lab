#include <stdio.h> 

/* this program helps to understand how to assign bit to integer
   and manage memory usage. 
   
   Note: you can't assigned a bit to other data type than integer
   
   the program uses 2^n-1 and for negative it converted the -3 to 
   positive then return the bits 
   
   example 1: x:5 which is  2^5-1 = 31.  that  means 31  highest number
   it can received which 31 bits is 1111
   
   example 2: type:4 which is 2^4-1=15 is the highest number 1111
   but when passed -3 the compiler covert it back to positive then take
   4 bit from the positive then return it 
    converting -3 using two's complement
    
    3 = 0000 0000 0000 0000 0000 0000 0000 0011 
    
    convert it to positive; convert zeros to 1 and 1's to 0 
    -------------------------------------------
    1111 1111 1111 1111 1111 1111 1111 1100
    seecond complement 
    +1 
    -------------------------------------------
    1111 1111 1111 1111 1111 1111 1111 1101
    
    now take 4 bit which is 1101, which gives 13 . 
*/ 

struct asigning_bit{ 
    
   unsigned int x:5; //assigned 5bits instead of 4byte
    float    y; 
   unsigned  int reserved:10; 
   unsigned  int type:4; 
   unsigned int  index:18; //assigned 18bits instead of 4byte. 
   char   arr[12]; 
   char  a; 
   
    
    
}; 





int main (){ 
    
    
    struct asigning_bit packed_data= { 31, 3.3, 1023, -3, 19,"usman", 'W'} ; 
    
    struct asigning_bit *ptr_handler=&packed_data;
    
    printf("%u  %u %u  %e %s %c \n"  , ptr_handler->x, ptr_handler->type, 
    ptr_handler->reserved, ptr_handler->y, ptr_handler->arr, ptr_handler->a); 
    
    
    
    
    
} 
