#include <stdio.h>
// doubly linked list 


struct values{ 
    
    
    int n; 
    struct values  *next; 
    struct values *back; 
}; 


int main()
{
   
   struct values n1,n2,n3, *pointer_handler,*pointer_handler_back; 
   
   n1.n=100; 
   n2.n=200;
   n3.n=500; 
   
   pointer_handler=&n1;
   n1.next=&n2;
   n1.back=pointer_handler; 
   
   n2.next=&n3;
   n2.back=&n1; 
   
   n3.next=(struct values *)0; 
   n3.back=&n2;  
   
   
   
   
   while ( pointer_handler != (struct values *)0){ 
       printf("%i\n",pointer_handler -> n); 
        pointer_handler=pointer_handler -> next; 
       
/* Guard needed: after pointer_handler = pointer_handler->next
 * runs on n3, pointer_handler becomes NULL (n3.next == 0).
 * Dereferencing NULL with -> back would segfault, so we only
 * read ->back when pointer_handler is non-NULL.
 */ 
        if ( pointer_handler != (struct values *)0)
        pointer_handler_back= pointer_handler -> back; 
         
        
     
     
   } 
}
