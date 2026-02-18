#include <stdio.h>
#include <math.h>
#include "logStream.h"

#define LOGGING 1
double f(double x){
    return x*cos(x)-sin(x);
}

double df(double x){
    return -x*sin(x);
}

int main(){
    double x=12,fn,dfn, precision=1e-12;
    int maxIter=10000, iter=0;

    fn = f(x); dfn = df(x);

    #if LOGGING 
        logInitialise("newton_raphson");

        int outDigs=0,decDigs=12,tOutDig=0,tInDig=0,inDigs=0;
        double tmp=0;
        tmp=fabs(fn);

        while(tmp>0.999){tmp/=10;outDigs++;}
        tOutDig=outDigs+decDigs+2;

        tmp=fabs(x);

        while(tmp>0.1){tmp/=10;inDigs++;}
        tInDig=inDigs+decDigs+2;
    #endif

    while(fabs(fn)>precision){
         #if LOGGING
            streamLog("%4d | %*.*lf | %*.*lf \n",iter, tInDig,decDigs,x, tOutDig,decDigs,fn);
        #endif

        if(iter>=maxIter){
            WARNING(DISTANT_CONVERGENCE, maxIter);
            break;
        }

        x -= fn/dfn;
        fn = f(x); dfn = df(x);
        iter++;

    }
    #if LOGGING
        streamLog("%4d | %*.*lf | %*.*lf \n",iter, tInDig,decDigs,x, tOutDig,decDigs,fn);
        logClose();
    #endif

    printf("Root is approximately %.10lf\n", x);
    return 0;
}