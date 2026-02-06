#include <stdio.h>

int main(){
	double x,a;	int n,t;

	printf("For (1+x)^a\n            Enter x : ");scanf("%lf",&x);
	printf("            Enter a : "); scanf("%lf",&a);
	printf("            Accuracy: "); scanf("%d",&n);

	double result = 1;

	for (t=n-1;t>=0; t--){
		result = 1 + result*x*(a-t)/(1+t);
	}

	printf("\t (1 + %.4lf)^%.3lf is %.8lf \n", x,a,result);

	return 0;
}
