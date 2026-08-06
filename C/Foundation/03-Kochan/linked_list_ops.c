#include <stdio.h>
/* Basic operations on a singly linked list of struct values nodes:
 *   - New_insert():   insert a new node after a given node
 *   - Remove_values(): remove the node following a given node
 *   - consideration(): search the list for a node matching a value
 *
 * Uses a dummy head node (Push_front) so insertion/removal at the
 * front of the list doesn't need special-case code.
 */ 


struct values {
	int x;

	struct values *next;

};

struct values *Remove_values (struct values *remover) {
    
    struct values *checker=remover -> next; 
    
    if ( checker != (struct values *)0 )
    // 
    remover -> next = checker -> next; 
        

 return checker; 

}

struct values *New_insert(struct values *new_number, struct values *old_n2_link) {

	// remember n2 hold n3 address so the adddress is pass here to n4
	new_number-> next = old_n2_link -> next;


	// n2 address change to new_number address here which is n4
	old_n2_link -> next = new_number;

}

//allow the another input from the user;
void new_input(struct values *new_input) {


	printf("%s","Enter the next number: ");
	scanf("%i",&new_input -> x);

	new_input -> next= (struct values *)0;


}


struct values * const consideration ( struct values *pointer_handler,  const int user_input) {


	while ( pointer_handler != (struct values  * )0 )

		if ( pointer_handler -> x == user_input)
			return pointer_handler;

		else
			pointer_handler = pointer_handler -> next;



	return (struct values *)0;



};



int main()
{
	struct values n1,n2,n3,n4,new_start, Push_front;

	struct values *holder, *start=&Push_front;




	int user_input;


	printf("%s", "Enter your values: ");
	scanf("%d",&user_input);

	n1.x=300;
	n1.next=&n2;
	n2.x=400;
	n2.next=&n3;
	n3.x=100;
	n3.next= (struct values *)0;
	Push_front.next=&n1;

	// take new user input
	new_input(&n4);

	new_input(&new_start);

	// now connect n1 to new_start
	New_insert(&new_start,&Push_front);


	New_insert(&n4,&n2);


	Remove_values(&n2); 
  

    // start -> next pointing to push_back.next . becuase push_front is dummy pointer and it has no vlaue 

	holder=consideration( start -> next, user_input);


	if ( holder != (struct values *)0 )

		printf("Found %i\n", holder -> x);
	else
		printf ("Can't be found sir\n");






}

