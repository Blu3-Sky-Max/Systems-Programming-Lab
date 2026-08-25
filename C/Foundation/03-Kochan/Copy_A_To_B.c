#include <stdio.h> 
#include <sys/stat.h> 

/* program allow user to enter their path
 * First path(__User_Input):the path of the copied file including the name of the file e.g  (/etc/fstab)
 *
 * second path(__User_Output):output name where you want to copy the file tooalso can also be like e.g /home/blue/usman_fstab.txt. 
 *
 * then the apply chmod on the file to allow only owner to rwx. 
 */ 

FILE *__INPUT,*__OUTPUT; 


int main () { 

char __User_Input[51], __User_Output[51]; 

 int holder, __Change_File_Mode; 

   printf("%s", "Enter name of file to be copied:" );
   scanf("%50s", __User_Input); 

   printf("%s", "Enter your  output file: " ); 
   scanf("%50s", __User_Output); 
 /* You can just use one return like 
 *  if ( ( __INPUT=fopen(__User_Input, "r")) && ( __OUTPUT= fopen(__User_Output, "a")) == NULL){
    perror("ERROR");
     return 20;
}  
*/

 
 if ( ( __INPUT=fopen(__User_Input, "r"))  == NULL){  
    perror("ERROR"); 
     return 20; 
}
 // append if you wanted to copy to existing file. 
  
  if ( ( __OUTPUT= fopen(__User_Output, "a")) == NULL) { 
      perror ("ERROR");
  return 21;   
} 


while ( ( holder=getc(__INPUT)) != EOF ) 
       
  putc(holder,__OUTPUT); 

 fclose(__INPUT); 
 fclose (__OUTPUT);







printf("File has been copied successfully\n"); 


if((__Change_File_Mode=chmod(__User_Output, 0700))  !=0) 
perror("Chomd"); 
else 
 printf("Change user permission successfully\n"); 

 

} 
