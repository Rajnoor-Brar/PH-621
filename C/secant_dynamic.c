#include <stdio.h>
#include <math.h>
#include "logStream.h"

double f(double x){
    return x*x - 2;
}

int main(){
    double x0=1.0, x1=2.0,r,f0,f1, precision=1e-12;
    int maxIter=10000, iter=0;

    f0 = f(x0); f1 = f(x1);
    while(f1>precision){
        r = x0 - (f0*((x1-x0)/(f1-f0)));
        x1
        f0 = f1; f1 = f(x1);
        if(++iter>maxIter){
            WARNING(UNSTOPPING_LOOP);
            break;
    }

    printf("Root is approximately %.10lf\n", x1);
    return 0;
}