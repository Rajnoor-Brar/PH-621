#include<stdio.h>
#include"f_logE.h"
#include"f_powE.h"
#include"f_zeta.h"

int main(){
	double s;	int n;

	printf("For Zeta(s) upto Nth term , \n");
	printf("                            s = ");scanf("%lf",&s);
	printf("                            N = ");scanf("%d",&n);

	double result=zeta(s,n);

	printf("\t Zeta(%.4lf) = %.10lf \n",s,result);

	return 0;
}
