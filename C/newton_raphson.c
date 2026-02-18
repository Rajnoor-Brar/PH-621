#include <stdio.h>
#include <math.h>
#include "logStream.h"

double f(double x){
    return x*x - 2;
}

double df(double x){
    return 2*x;
}

int main(){
    double x=90,fn,dfn, precision=1e-12;
    int maxIter=10000, iter=0;

    // logInitialise("newton_raphson");

    fn = f(x); dfn = df(x);
    while(fabs(fn)>precision){
        x -= fn/dfn;
        fn = f(x); dfn = df(x);

        // streamLog(" %*.*lf | %*.*lf \n", 20,12,x, 20,12,fn);
        if(++iter>=maxIter){
            WARNING(DISTANT_CONVERGENCE, maxIter);
            break;
        }
    }
    // logClose();
    printf("Root is approximately %.10lf\n", x);
    return 0;
}