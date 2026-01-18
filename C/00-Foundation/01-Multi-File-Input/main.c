#include <stdio.h>

void  p(int);
void f();
 int main(){
	 int x;
	 int y;
	 printf("enter your first  number: ");

	 scanf("%d",&x);
	 printf("Enter your second number: ");
    	 scanf("%d",&y);
	 int sum=x+y;
	int usman =x+y+y; 
	puts("");
	 p(sum);
	puts("");
	 f(); puts("");
	 printf("the sum of the last was added twice that's why we have %d\n ",usman);
 }
