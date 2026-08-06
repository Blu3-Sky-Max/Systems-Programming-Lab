#include <stdio.h>

void exchange(int * const p, int * const p1) {

	int exchange;
	exchange=*p;
	*p=*p1;
	*p1=exchange;




}
int main (void) {
	int first=10;
	int second=20, *pointer, *pointer_handler;

	pointer=&first;
	pointer_handler=&second;


	printf("first= %i  second = %i \n",*pointer, *pointer_handler);

	exchange(pointer,pointer_handler);

	printf("first= %i  second = %i\n",*pointer, *pointer_handler);

	exchange(pointer,pointer_handler);
	printf("first= %i  second = %i \n",*pointer, *pointer_handler);




}
