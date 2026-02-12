#include<stdio.h>
#include <stdlib.h>
#include<math.h>

void polynomialInput(int n, double coeffs[n]){
    int i,k;
     for (i=1;i<=n+1;i++) {
      k=n+1-i;

      if (i<=n) {
        printf("x^%d (",k); scanf("%lf",&coeffs[i]); printf(") + ");
    }
      else if (i==n+1) {scanf("%lf",&coeffs[i]);  printf(" = 0");}
    }
}

void polynomialDisplay(int n, double coeffs[n]){
    int i,k;
    printf("\nFunction is:\n");

    for (i=1;i<=n+1;i++){
      if (i==1){
        if (coeffs[i]!=1 && coeffs[i]!=0) {k=n+1-i; printf("%f(x^%d)",coeffs[i],k);}
        else if (coeffs[i]==1) {k=n+1-i; printf("x^%d",k);}
        else if (coeffs[i]==0) {printf("0");}
      }
      else if (i<n && i!=1){
        if (coeffs[i]!=1 && coeffs[i]!=-1 && coeffs[i]>0) {k=n+1-i; printf(" + %f(x^%d)",coeffs[i],k);}
        else if (coeffs[i]!=1 && coeffs[i]!=-1 && coeffs[i]<0) {k=n+1-i; printf(" - %f(x^%d)",fabs(coeffs[i]),k);}
        else if (coeffs[i]==1) {k=n+1-i; printf(" + x^%d",k);}
        else if (coeffs[i]==-1) {k=n+1-i; printf(" - x^%d",k);}
        else if (coeffs[i]==0) {continue;}
      }
      else if(i==n){
        if (coeffs[i]!=1 && coeffs[i]>0) {printf(" + %fx",coeffs[i]);}
        else if (coeffs[i]!=1 && coeffs[i]<0) {printf(" - %fx",fabs(coeffs[i]));}
        else if (coeffs[i]==1) {printf(" + x");}
        else if (coeffs[i]==-1) {printf(" - x");}
        else if (coeffs[i]==0) {continue;}
      }
      else if(i==n+1){
        if(coeffs[i]>0){printf(" + %f = 0",coeffs[i]);}
        else if(coeffs[i]<0){printf(" - %f = 0",fabs(coeffs[i]));}
        else if(coeffs[i]==0){printf(" = 0");}
      }
    }
}

double polynomial(int type, double x){
       // type 0 for initialisation, 1 for evaluation
  int i,j,k;
  
  double semsol[21],sol=0;

  static int n;
  static double coefs[20];

  //----------------------------Input-------------------------------------------
  if (type==0){
     printf("Enter order of equation:\n"); scanf("%d",&n);
     
    polynomialInput(n, coefs);

    polynomialDisplay(n, coefs);
    return 0;
  }

  //-----------------------------Function---------------------------------------
  if (type==1){
    for (i=1;i<=n+1;i++) {
      k=n+1-i;
      semsol[i]=1;

      for (j=1;j<=k;j++) {semsol[i]*=x;}
      semsol[i]*=coefs[i];
    }

    for (i=1;i<=n+1;i++) {sol+=semsol[i];}
    return sol;
  }
return 0;

}