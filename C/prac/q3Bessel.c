#include<stdio.h>
int main(){
	double x; int i,n;

	printf("For Bessel of first kind, J0(x),\n");
	printf("                                 Enter x : "); scanf("%lf",&x);
	printf("                                 Accuracy: "); scanf("%d", &n);
	double result = 1, xx = x*x*0.25, precision=1e-8;
	for(i=n-1;i>0;i-=1){
		result = 1 - ((result * xx) / (i*i));
                if ((term<precision && term>0)||(term<0 && term>(-1*precision))){printf("\t Term (%g) is below precision threshold. Breaking at step %d.\n",term,i);break;}
        }
        if ((term>precision && term>0)||(term<0 && term<(-1*precision))){printf("\t Last term (%g) has NOT dropped below precision threshold. Answer may not be accurate.\n", term);}

	printf("J0(%.4lf) = %.8lf \n",x,result);
	return 0;
}
