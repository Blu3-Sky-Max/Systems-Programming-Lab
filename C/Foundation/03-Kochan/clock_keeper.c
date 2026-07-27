#include <stdio.h> 
#include <stdbool.h> 

struct Time{
    int hour,
    min,
    sec;
};

struct date {
    int month,
     year,
     day;


};

/// handle Leap year 
bool Leap_year(struct date d){

     bool Leap_year_flag=true;

  if ( (d.year %4 ==0 && d.year % 100 !=0 ) || d.year % 400 ==0 )
         Leap_year_flag=true;
    else
         Leap_year_flag=false;

    return Leap_year_flag;
}

// func to check if it's leap year. 
int Number_Of_Days(struct date d){


    int days;

   

    const int days_per_month [12]={ 31, 28,31,30,31,30,31,31,30,31,30,31 };

    if ( Leap_year(d) == true && d.month  == 2)
    days=29;
    else
    days=days_per_month[ d.month - 1 ];

    return days ;



}

// handle time
struct Time time_update (struct Time input){
    ++input.sec;

    if ( input.sec == 60 ){
      input.sec=0;
      ++input.min;

      if (input.min == 60){
          input.min=0;
          input.hour++;


         if (input.hour == 24)
          input.hour=0;
          }
}
return input; 
 
};  

//handle date here
struct date date_update(struct date new_date){

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


}; 
// Add the two struct to be easily acccess 
struct date_and_time{ 
    
    struct Time s_time;
    struct date s_date; 

}; 


struct  date_and_time clock_keeper (struct date_and_time input) { 
    
      struct date_and_time output;
      int midnight=0; 
      
      
      // handle midnight 
      
      midnight= ( input.s_time.hour ==23 && input.s_time.min ==59 && input.s_time.sec == 59) ; 
     
     //handle time
      output.s_time= time_update(input.s_time);
      
      //handle date here
      if (midnight > 0 )
      output.s_date= date_update(input.s_date); 
       else
       output.s_date=input.s_date; 
       
       
       return output; 
      
     
    
    
} ; 



int main (){ 
    
   struct  date_and_time now = { {23, 59, 59}, {2, 2000, 28} }; 
     now =clock_keeper(now); 
    
     printf("%.2i:%.2i:%.2i  %i/%i/%i \n  ",now.s_time.hour,now.s_time.min,now.s_time.sec,now.s_date.day,
     now.s_date.month,now.s_date.year);
    
    
} 
