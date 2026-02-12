#include <stdio.h>
#include "sine.h"
#include "cosine.h"

int main(){
	int acc; double val,sin,cos,sum;

	printf("Enter accuracy for terms ");scanf("%d",&acc);
	printf("Enter the value "); scanf("%lf",&val);
	sin = sine(val,acc);
	cos = cosine(val,acc);
	sum = expo(sin,2) + expo(cos,2);
	printf("Value of sin(%.3lf) is %.6lf \n         cos(%.3lf) is %.6lf \n         sin^2+cos^2 (%.3lf) is %.6lf \n",val,sin,val,cos,val,sum);
	return 0;
}
