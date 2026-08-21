typedef  enum  { Jan=1, Feb, Mar, Apr, May, Jun, July, Aug, Sep, Oct, Nov, Dec} month; 


// using typedef for easy call back 
typedef char * (*funky)(month); 



#include <stdio.h>
 
 char * Month_name(month User_input){ 
     
     
     
     // starting with "" cause array start at zero and no year at start at zero 
     char * arr []= { "",  "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
     
     
     return arr[User_input]; 
     
     
     
     
 } 

int main()
{
    month User_input;
    
    funky pointer_handler; 
    
    printf("%s", "Enter Month number: "); 
    
    scanf("%i", &User_input);
    
   
    
    if (User_input < 1 || User_input > 12)
        return -1;  
    
    
     pointer_handler=Month_name;
     printf("%s\n", pointer_handler(User_input)); 
}
