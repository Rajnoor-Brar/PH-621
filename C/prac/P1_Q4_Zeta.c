#include<stdio.h>
#include"logE.h"
#include"powE.h"
#include"zeta.h"

int main(){
	double s;	int n;

	printf("For Zeta(s) upto Nth term , \n");
	printf("                            s = ");scanf("%lf",&s);
	printf("                            N = ");scanf("%d",&n);

	double result=zeta(s,n);

	printf("\t Zeta(%.4lf) = %.10lf \n",s,result);

	return 0;
}
