#include <stdio.h>

int main(){
	double x,result=0,term=1;
	int i,n;

	printf("\t Enter value of x : ");scanf("%lf",&x);
	printf("\t Number of terms  : ");scanf("%d",&n);

	double xx = x*x, precision=1e-8;
	result = x; term = x;

	for (i=1;i<n;i++){
		term *= (-1*xx*(2*i-1)/((2*i+1)*i));
		result += term;
		if ( (term<precision && term>0) || (term<0 && term>(-1*precision)) ){
			printf("\t\t Term (%g) is below precision threshold. Breaking at step %d.\n",term,i);break;
		}
	}
	if ( (term>precision && term>0) || (term<0 && term<(-1*precision)) ){
		printf("\t Last term (%g) has NOT dropped below precision threshold. Answer may not be accurate.\n", term);
	}

	result *= 1.128379671;

	printf("\t erf(%.4lf) is %.10lf \n",x,result);

	return 0;
}
