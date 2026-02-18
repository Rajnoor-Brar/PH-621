#include <stdio.h>
#include <math.h>
#include "logStream.h"
// #include"polynomial.h"

double func(double x){
    return (x*cos(x)-sin(x));
    // return polynomial(1,x);
}

void bisect(double a, double b){
    double r,s,y,q,c,diff, threshold;
    int iter=0;

    int tmp = (int)fmax(fabs(a),fabs(b)), digs=0, decimals=15, maxIter=10000;

    while (tmp>0){tmp/=10; digs++;}

    logInitialise("bisection");
    streamLog("%*c c %*c|%*c f(c)\n", (digs+decimals+2)/2,' ',(digs+decimals)/2,' ',(digs+decimals+2)/2,' ');

    r=func(a);  s=func(b);
    y=r*s;  diff=1e-12, threshold=1e-12;  c=0;q=0;

    if (y>0) {
        printf("Retry by shifting values on number line");
    }

    else if (y==0) {
        printf((r==0 && s==0) ? "Both roots (%f) are same" : "%f is a root", (r==0) ? a : b);
    }

    else if (y<0){
        c=(a+b)/2; q=func(c);
        while (b-a>=diff && fabs(q)>=threshold){
            c=(a+b)/2;  r=func(a);  s=func(b);  q=func(c);

            if (q == 0.0) {break;} 
            else {(q*r<0) ? (b=c) : (a=c);}

            streamLog(" %*.*lf | %*.*lf \n", digs+decimals+2,decimals,c,digs+decimals+2,decimals,q);
            
            if(++iter>maxIter){
                WARNING(UNSTOPPING_LOOP);
                break;
            }
        }

        printf("Value of root is %.10lf\n", c); printf("Number of iterations: %d\n", iter); return;
    }
    logClose();
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
