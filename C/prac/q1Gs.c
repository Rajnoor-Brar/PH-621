#include <stdio.h>

int main(){

	double r;int n,i;

	printf("Enter the base, 'r' : ");scanf("%lf",&r);
	printf("Enter the value of N : ");scanf("%d",&n);

	double series = 1;
	for  (i=1; i<n ; i++){
		series = 1 + r*series;
	}

	printf("Result of series is %.6lf\n",series);
	return 0;
}
