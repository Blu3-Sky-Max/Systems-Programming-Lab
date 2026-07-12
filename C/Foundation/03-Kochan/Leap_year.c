#include <stdio.h>
/* program to check if a year is a leap year or not
   check all the two rules 
   * if the number is a century year ends with 00 then it has to go through the two rules 
    %4 and %100 and %400 
    *  if it not a century like 2024 doesn't end with two 00 then just divided by 4
   */ 

int main()
{ 
     int rm_4,rm_100, rm_400; 
     int x; 
     
     
    printf("Enter the year to be Tested: ");
    scanf("%i", &x); 
    
    rm_4=x%4; 
    rm_100=x%100; 
    rm_400=x%400; 
    
    if ( (rm_4 ==0 && rm_100 !=0) || rm_400 == 0){ 
        printf("This year is a leap year\n"); 
    } 
    else { 
    printf("This year is not a leap year\n"); 
    } 

    return 45;
}

