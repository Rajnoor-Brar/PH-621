#include <stdio.h>
#include <math.h>
// #include"polynomial.h"

double func(double x){
    return (x*cos(x)-sin(x));
    // return polynomial(1,x);
}

void bisect(double a, double b){

    FILE *bisectionLog = fopen("bisectionLog.txt","w");
    fprintf(bisectionLog,"        c        |         f(c)\n");

    double r,s,y,q,c,diff, threshold, iter=0;
    r=func(a);  s=func(b);
    y=r*s;  diff=1e-12, threshold=1e-12;  c=0;q=0;

    if (y>0) {printf("Retry by shifting values on number line"); return;}

    else if (y==0) {
        if (r==0 && s!=0){printf("%f is a root",a);}
        else if(r!=0 && s==0){printf("%f is a root",b);}
        else if(r==0 && s==0){printf("Both %f and %f are roots",a,b);}
    }

    else if (y<0){

    while (b-a>=diff || fabs(q)<=threshold){
        c=(a+b)/2;  r=func(a);  s=func(b);  q=func(c);

        if (q == 0.0) {break;}  else if(q*r<0){b=c;}  else if(q*s<0){a=c;}
        
        fprintf(bisectionLog," %.15lf | %.15lf \n",c, q);
        iter++;
    }

    printf("Value of root is %.10lf\n", c); printf("Number of iterations: %lf\n", iter); return;
    }

    fclose(bisectionLog);
    return;
}
// --------------------------------------------------------------------------------------------------
int main() {
//   polynomial(0,0);

  double a,b;
  printf("Enter end points of range to look for:\n");
  scanf("%lf",&a); printf("\033[A\r\033[J %lf to ",a); scanf("%lf",&b);

  bisect(a,b);
  return 0;
}
