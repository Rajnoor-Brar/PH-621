#include <stdio.h>
#include <math.h>
#include "logStream.h"

#define LOGGING 0
double f(double x){
    return x*x - 2;
}

int main(){
    double x0=1.0, x1=3.0,f0,f1, precision=1e-12;
    int maxIter=10000, iter=0;

    FILE *inputFile = fopen("inputs/secant.in", "r");
    if (!inputFile) {
        perror("fopen");
        return 1;
    }
    fscanf(inputFile,"%lf %lf %lf %d",&x0,&x1,&precision,&maxIter);
    fclose(inputFile);

    #if LOGGING
        logInitialise("secant");
    #endif

    f0 = f(x0); f1 = f(x1);

    while(fabs(f1)>precision){
        x1 = x0 - (f0*((x1-x0)/(f1-f0)));
        f1 = f(x1);
        #if LOGGING 
            streamLog(" %*.*lf | %*.*lf \n", 20,12,x1, 20,12,f1); 
        #endif
        if(++iter>maxIter){
            WARNING(UNSTOPPING_LOOP);
            break;
        }
    }
    #if LOGGING
        logClose();
    #endif
    printf("Root is approximately %.10lf\n", x1);
    return 0;
}