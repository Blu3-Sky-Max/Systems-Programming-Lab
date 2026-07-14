#include <stdio.h>



int main()
{
    long long convert_number; int base, index=0, output; 
    
  const char base_digit[16]={ '0', '1', '2', '3','4', '5','6', '7','8',
                               '9','A','B','C','D','E','F'} ;   
  int reminder_holder[128]; 
  
  printf("Enter the number to be converted: "); 
  scanf("%lld", &convert_number); 
  printf("Base? ");
  scanf("%d", &base);
  
  if ( convert_number <=1 || base <=1 ){  
      printf("Enter a positive number - greater than 1  sir\n");
      return 45;
      
  } 
  // condition here make it stronger

  while ( base > 1  &&  convert_number !=0 ){ 
      reminder_holder[index]= convert_number % base; 
       convert_number = convert_number / base; 
       ++index; 
  } 
  
  for (--index; index >=0; index --){ 
 //     output=reminder_holder[index]; 
      printf("%c", base_digit [ reminder_holder[index] ]);

}
 puts("");  
} 
