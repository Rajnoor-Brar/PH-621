#include <stdio.h>
#include "f_erf.h"

int main(){
	double x, result;
	int n;

	printf("\t Enter value of x : ");scanf("%lf",&x);
	printf("\t Number of terms  : ");scanf("%d",&n);

	result = erfunc(x,n);

	printf("\t erf(%.4lf) is %.10lf \n",x,result);

	return 0;
}
