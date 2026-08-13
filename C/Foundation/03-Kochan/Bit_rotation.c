#include <stdio.h>
/*  note: this input works on a machine that uses 64 bit cpu 
 and 32 bits for unsigned integer
   
   remember: unsigned integer magitude is 32bits max 
   
  example 1: word 1 is 0xabcdef00u which is 
  1010 1011 1100 1101 1110 1111 0000 0000 
  
  bits = input >> (32 -8) basiscally shifting by 24 
  to the right  
  
  bits = 0xab  which is 1010 1011 
  
  resutlt = input << n | bits ; 
  so shifiting input to the left by 8  which is 
  1100 1101 1110 1111 0000 0000 0000 0000
   and using  OR | which is +  bits 
  0000 0000 0000 0000 0000 0000 1010 1011
  ---------------------------------------
   1100 1101 1110 1111 0000 0000 1010 1011
   
gives: 0xcdef00ab
   
  */
 
unsigned int rotate_shift (unsigned int input, int shift){ 
     unsigned int result,bits; 
     
    // if input of shift is less than 0 
    
    if ( shift > 0 )
         shift = shift % 32; 
         else
         shift = -(-shift %32);
    
   if (shift == 0 )
    result= input; 
    else if ( shift > 0){ 
        // left rotate <<  
        
        bits=  input >> (32 - shift);
        result = input << shift | bits; 
    } 
        
        else { 
            // right shift >> 
            
            bits = input << (32 - shift); 
            result = input >> shift  | bits;
            
        } 
        
        
        return result; 
        
} 

int main()
{
    
    
    
    unsigned int word1=0xabcdef00u , word2=0xffff1122u; 
   
   
   printf("%x\n",rotate_shift(word1, 8)); 
   printf("%x\n",rotate_shift(word1, -16));
   printf("%x\n",rotate_shift(word2, 4));
   printf("%x\n",rotate_shift(word2, -2));
   printf("%x\n",rotate_shift(word1, 0));
   printf("%x\n",rotate_shift(word1, 4));
    
    
    
    
    
} 
   

