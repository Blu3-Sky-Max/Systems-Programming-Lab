#include <stdio.h>
#include <math.h>
void p();
void man();
int main (){

	const int x=3;
	int sum=0;
	int arr[x];
	for (size_t i=0; i<x; i++){
		printf("Enter your number: ");
	scanf("%d",&arr[i]);
 sum+=arr[i]; 
	}
	for(int i=0; i<x; i++){
	printf("%d\t", arr[i]+2); 
	}
	puts("");
	printf(" the sum of your input is %d\n", sum);

	p();
	puts("");
	man();
}
