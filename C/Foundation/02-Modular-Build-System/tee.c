#include <stdio.h>


void  man(){
 const size_t m=5;
 float array[]= {3.2,4.5,2.1,5.8,4.4};
	for(int i=0; i<m; i++){
	printf("%.3f\t",array[i]);}
	puts("");
}
