#include<stdio.h>
#include"f_bessel_K1_O0.h"

int main(){
	double x; int n;

	printf("For Bessel of first kind, J0(x),\n");
	printf("                                 Enter x : "); scanf("%lf",&x);
	printf("                                 Accuracy: "); scanf("%d", &n);
	
	double result = bessel_K1_O0(x,n);

	printf("J0(%.4lf) = %.8lf \n",x,result);
	return 0;
}
