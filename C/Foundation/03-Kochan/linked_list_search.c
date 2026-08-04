#include <stdio.h>


struct values {
	int x;

	struct values *next;

};

struct values * const consideration ( struct values *pointer_handler,  const int user_input) {


	while ( pointer_handler != (struct values  * )0 )

		if ( pointer_handler -> x == user_input)
			return pointer_handler;

		else
			pointer_handler= pointer_handler -> next;

	
	
	return (struct values *)0;



};



int main()
{
	struct values n1,n2,n3;
	struct values *holder, *start=&n1;

	int user_input;


	printf("%s", "Enter your values: ");
	scanf("%d",&user_input);

	n1.x=300;
	n1.next=&n2;
	n2.x=400;
	n2.next=&n3;
	n3.x=100;
	n3.next= (struct values *)0; // or put 0 or NULL ; 


	holder=consideration( start, user_input);


	if ( holder != (struct values *)0 )

		printf("Found %i\n", holder -> x);
	else
		printf ("Can't be found sir\n");






}

