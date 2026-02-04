#include <stdio.h>

int main(){
	double x,a;	int n,i,t;

	printf("For (1+x)^a\n            Enter x : ");scanf("%lf",&x);
	printf("            Enter a : "); scanf("%lf",&a);
	printf("            Accuracy: "); scanf("%d",&n);

	double result = 1,sum=1,term=1;

	for (t=n-1;t>=0; t--){
		i=n-t;
		result = 1 + result*x*(a-t)/(1+t);
		term=(term*x*(a+1-i))/i;
		sum+=term;
        }

	printf("\t (1 + %.4lf)^%.3lf is %.8lf | %.8lf", x,a,result, sum);

	return 0;
}
