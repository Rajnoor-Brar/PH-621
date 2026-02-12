#include <stdio.h>

int main(){

int A = 5;
int *B = &A;

printf("A   = %d\n", A);
printf("&A  = %p\n", (void*)&A);

printf("B   = %p\n", (void*)B);
printf("*B  = %d\n", *B);
printf("&B  = %p\n", (void*)&B);
	return 0;

}
