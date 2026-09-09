#include <stdio.h> 
#include <stdlib.h> 
#include <stdlib.h> 

/*Program takes an integer argument from the terminal 
 * for the last node to be inserted  the take the new 
 * input to the last node also shift the last null pointer
 * to allow new input number inside and store it in a file 
 */ 

 
#define red "\033[31m" 
#define reset "\033[0m" 
#define yellow  "\033[33m"  

FILE * __OUTPUT_CLI_MALO; 
 
struct __control{ 

   int input; 
   struct __control * __next_node; 

};

/* removing a node from  the  list  */ 
struct __control  * remove_node(struct __control * node_remove){ 
     
   struct __control *__remover= node_remove -> __next_node; 
  
  if (  __remover  != NULL  ) 
   
  node_remove -> __next_node = __remover -> __next_node; 
 

 return __remover;  

}  
 
 /* changing the values of second input here */ 

void  * change_input(  int  * const  values_to_change){ 
  
 
    *values_to_change=490 ;


}  

 
struct __control *new_entry(struct __control *__passed, const char * __terminal_input) { 
  

/*  the head pointer to the end of the loop before inserting
 *  explination here: 
 *  the __next_node is check to see if the next node is empty 
 *  if it's it break the loop 
 */  
  while (__passed -> __next_node != NULL) 
     __passed=__passed -> __next_node; 

/* then when it break we add a single size of struct to it */ 
   
struct __control  *  __new_input = malloc(sizeof(struct __control)); 

if ( __new_input !=NULL  && __passed != NULL){   
  //convert the terminal input to integer 
   
__new_input -> input= atoi (__terminal_input); 
  __passed -> __next_node  = __new_input; 
 __new_input -> __next_node=NULL;
 } else
  exit (70); 

// can alsow return just __passed
 return __passed -> __next_node; 

}  




int main ( int __argc,  char * __argv[]) { 

 struct __control _first_,_second_,_third_, *__Head_ptr, _fourth_,_fifth_, *__new_head; 


//output the file here
__OUTPUT_CLI_MALO=fopen("/home/blue/__Output_mallo" , "w+"); 


_fourth_.input=_first_.input=_second_.input=70, _fifth_.input = _third_.input=85; 

  change_input(&_second_.input); 


// user to enter the new entry input on terminal; 
 if (__argc !=2 ){ 
  fprintf(stdout, red "The Input from the cli must be two: a.out & any number\n"reset ); 
 exit (20); 
} 



__Head_ptr=&_first_; 
_first_.__next_node=&_second_, 
_second_.__next_node=&_third_,  

_third_.__next_node=&_fourth_, 

_fourth_.__next_node=&_fifth_,
_fifth_.__next_node=NULL;

struct __control *output=new_entry(__Head_ptr,__argv[1] ); 


 fprintf(__OUTPUT_CLI_MALO, "Output before removing a node\n" ); 

 while (__Head_ptr != NULL) {

// for  terminal output should change ____OUTPUT_CLI_MALO to stdout 
  fprintf(__OUTPUT_CLI_MALO, "%i\n", __Head_ptr -> input) ; 
   __Head_ptr= __Head_ptr -> __next_node; 

 
}
 remove_node(&_fifth_); 

__new_head=&_first_;  
 fprintf(__OUTPUT_CLI_MALO, "Output After a node is been remove\n" );
  
 while (__new_head != NULL) {

// for  terminal output should change ____OUTPUT_CLI_MALO to stdout 
  fprintf(__OUTPUT_CLI_MALO, "%i\n", __new_head -> input) ;
   __new_head= __new_head -> __next_node;


}



 free(output); 
/* NULL it cause after adding the last number from 
 * from terminal . the 5th is now a dangling pointer
 * cause when you free the *output now the address is 
 * not safe to use
 *
 * for safety: 
 *
 */ 

_fifth_.__next_node=NULL;
 
fclose (__OUTPUT_CLI_MALO); 
 exit (0); 

} 
