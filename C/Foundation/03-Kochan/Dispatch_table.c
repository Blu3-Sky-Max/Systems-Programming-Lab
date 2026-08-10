#include <stdio.h> 
#include <string.h>


char msg[]="Machine burnout since friday\n";

void cmd_hello(void) {

	printf("Welcome message!!!\n");

}

void machine_burnout_message(void) {

	printf(msg);

}
void cmd_bye() {


	printf("Good_bye sir \n");

}


// dispatcher table

struct command  {
	const   char  *name_search ;

	void(*handler)(void);  // function pointer field



} ;




int main () {

	char User_input[11];

	struct command values [] = {
		{ "hello", cmd_hello},
		{ "bye", cmd_bye },
		{ "burnout", machine_burnout_message }
	} ;


	printf("%10s", "Enter your string: ");
	scanf("%10s", &User_input); 



	for ( int i =0; i < sizeof(values) / sizeof(values[0]); i++) {
             // compare the string usint the built in func strcmp 
		if (strcmp( values[i].name_search, User_input) == 0 ) {
			values[i].handler();
			break;
		}


	}

}


