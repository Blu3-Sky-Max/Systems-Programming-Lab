#include <stdio.h> 
#include <stdbool.h> 

/* 
 * ====================================================================
 * PROGRAM: Date Updater & Calendar Logic
 * ====================================================================
 * How date rotation and logic works:
 * 
 * 1. User Input: 
 *    - The user provides a day, month, and year in main().
 * 
 * 2. Date Update (date_update):
 *    - The program checks if the current day has reached the maximum 
 *      number of days for that specific month (using Number_Of_Days).
 *    - CASE A (Middle of the month): If the day hasn't reached the 
 *      month's limit, it simply increments the day by 1 (day + 1).
 *    - CASE B (End of the year): If the day is at its limit AND the 
 *      month is December (12), it rolls over the year (year + 1) 
 *      and resets both the day and month to 1 (January 1st).
 *    - CASE C (End of a regular month): If the day is at its limit 
 *      for any other month, it rolls over the month (month + 1) 
 *      and resets the day to 1.
 * 
 * 3. Leap Year Calculation (Leap_year & Number_Of_Days):
 *   dd - To know when a month ends, February needs special handling.
 *    - Number_Of_Days fetches the max days from an array, but checks 
 *      if it's February and a leap year. If so, it returns 29 days 
 *      instead of 28.
 * ====================================================================
 */

 
struct date { 
    int month, 
     year,
     day; 

    
}; 
int Number_Of_Days( struct date d);



struct date date_update( struct date new_date ){ 
    
    struct date tomorrow; 
    
   
    
    
    if ( new_date.day != Number_Of_Days(new_date) ){ 
        tomorrow.day=new_date.day + 1; 
        tomorrow.month=new_date.month; 
        tomorrow.year=new_date.year; 
    } 
    else 
    if (new_date.month == 12 ){ 
        tomorrow.day=1; 
        tomorrow.month=1;
        tomorrow.year=new_date.year + 1;
        
    } 
    else{  
     tomorrow.day=1;
     tomorrow.month=new_date.month +1; 
     tomorrow.year=new_date.year; 
    } 
    
    return tomorrow; 



} ;
int Number_Of_Days(struct date d){ 
    
    
    int days;
    
    bool Leap_year(struct date d); 
    
    const int days_per_month [12]={ 31, 28,31,30,31,30,31,31,30,31,30,31 }; 
      
    if ( Leap_year(d)== true && d.month  == 2)
    days=29; 
    else
    days=days_per_month[ d.month - 1 ];
    
    return days ; 
    
    
    
} 
bool Leap_year(struct date d){ 
 
     bool Leap_year_flag=true; 
     
  if ( (d.year %4 ==0 && d.year % 100 !=0 ) || d.year % 400 ==0 )
         Leap_year_flag=true;
    else 
         Leap_year_flag=false; 
    
    return Leap_year_flag;
} 




int main(void){ 
    
 struct date today, tomorrow; 
     
    printf ("Enter today's date (dd/mm/year): ");
    scanf("%d / %d / %d",&today.day,&today.month,&today.year);
    
      if ( today.day > 31 || today.month > 12 ){ 
       printf("Enter a vaild day and month\n");
       return 2;
   } 
    
    // passing struct to fucn struct
    
    tomorrow=date_update(today); 
   
  
    printf("tomorrow's date is %i/%i/%i\n",tomorrow.day,tomorrow.month, tomorrow.year); 
    
    
       
    
     } 
