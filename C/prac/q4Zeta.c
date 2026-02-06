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

// int main_depreciated(){
// 	double precision=1e-12,s,ex=0,term; int i,n;

// 	printf("For Zeta(s) upto Nth term , \n");
// 	printf("                            s = ");scanf("%lf",&s);
// 	printf("                            N = ");scanf("%d",&n);

// 	double ns     = -1*s;
// 	double result = 0;

// 	for(i=1;i<=n;i++){
// 		ex   = ns*logE(i);
// 		term = powE(ex);
// 		result+=term;
// 	        if ((term<precision && term>0)||(term<0 && term>(-1*precision))){
// 				printf("\t Term (%g) is below precision threshold (%g). Breaking at step %d.\n",term,precision,i);
// 				break;
// 			}
// 	}\

// 	if ((term>precision && term>0)||(term<0 && term<(-1*precision))){
// 		printf("\t Last term (%g) has NOT dropped below precision threshold (%g). Answer may not be accurate.\n", term,precision );
// 	}

// 	printf("\t Zeta(%.4lf) = %.10lf \n",s,result);
// 	return 0;

// }
