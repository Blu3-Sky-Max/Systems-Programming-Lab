#include <stdio.h> 
#include <stdlib.h>  
/* copy from input_file to Outputfile
 * added some ansi color to it too 
 *
 */ 

FILE *__INPUT_FILE, * __OUTPUT_FILE;  

#define red "\033[31m" 

#define dark_white  "\033[37m" 
#define reset "\033[0m" 

int main (int argc, char * argv[]) { 


int holder; 


  // check the number of argument on the terminal 
  if (argc !=3){  
  fprintf(stdout, red"Need Two File Name; First: file to copy, Second: destination\n" reset);   
   exit (9); 
} 
 
/* you can change the options to append "a" to add to the file without erasing the content in the file */ 


 if ( (__INPUT_FILE=fopen(argv[1], "r") )  == NULL ||  (__OUTPUT_FILE= fopen(argv[2], "w+") )   == NULL) { 
     fprintf(stdout, dark_white "It's either The file to be copy is NULL or the output sir\n" reset);

    exit(40); 
} 


while ( ( holder=fgetc(__INPUT_FILE))  != EOF ) 
     fputc(holder, __OUTPUT_FILE);


 
fclose(__INPUT_FILE); 


fclose(__OUTPUT_FILE);   

   


  fprintf(stdout,"File Copied Successfully\n");
  exit (0);  
} 
