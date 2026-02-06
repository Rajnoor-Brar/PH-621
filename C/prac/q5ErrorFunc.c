#include <stdio.h>
#include "erf.h"

int main(){
	double x,result=0,term=1;
	int i,n;

	printf("\t Enter value of x : ");scanf("%lf",&x);
	printf("\t Number of terms  : ");scanf("%d",&n);

	result = erf(x,n);

	printf("\t erf(%.4lf) is %.10lf \n",x,result);

	return 0;
}
