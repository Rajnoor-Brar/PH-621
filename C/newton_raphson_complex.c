#include <stdio.h>
#include <math.h>
#include "logStream.h"

#define LOGGING 1

double u(double x, double y){
    return (exp(x)*cos(y)-1);
}

double v(double x, double y){
    return (exp(x)*sin(y));
}

double u_x(double x, double y){
    return exp(x)*cos(y);
}

double u_y(double x, double y){
    return -1*exp(x)*sin(y);
}

double v_x(double x, double y){
    return exp(x)*sin(y);
}

double v_y(double x, double y){
    return exp(x)*cos(y);
}

double J(double x, double y){
    return (u_x(x,y)*v_y(x,y) - u_y(x,y)*v_x(x,y));
}

int main(){
    double x=80.3,y=32,f_u,f_v,f_ux,f_uy,f_vx,f_vy,f_J, precision=1e-12;
    int maxIter=10000, iter=0;

    f_u = u(x,y); f_v = v(x,y); f_ux = u_x(x,y); f_uy = u_y(x,y); f_vx = v_x(x,y); f_vy = v_y(x,y);

    #if LOGGING 
        logInitialise("newton_raphson_complex");

        int outDigs=0,decDigs=12,tOutDig=0,tInDig=0,inDigs=0;
        double tmp=0;
        tmp=fmax(fabs(f_u),fabs(f_v));

        while(tmp>0.999){tmp/=10;outDigs++;}
        tOutDig=outDigs+decDigs+2;

        tmp=fmax(fabs(x),fabs(y));

        while(tmp>0.1){tmp/=10;inDigs++;}
        tInDig=inDigs+decDigs+2;
    #endif

    while(fabs(f_u)>precision && fabs(f_v)>precision){
        f_J = J(x,y);
    
        x -= (f_u*f_vy - f_v*f_uy)/f_J;
        y -= (f_v*f_ux - f_u*f_vx)/f_J;

        f_u  = u(x,y);   f_v  = v(x,y); 
        f_ux = u_x(x,y); f_vx = v_x(x,y);
        f_uy = u_y(x,y); f_vy = v_y(x,y);

        iter++;

        #if LOGGING 
            streamLog(" %*.*lf + i %*.*lf | %*.*lf + i %*.*lf\n", tInDig,decDigs,x,tInDig,decDigs,y, tOutDig,decDigs,f_u, tOutDig,decDigs,f_v);
        #endif

        if(iter>=maxIter){
            WARNING(DISTANT_CONVERGENCE, maxIter);
            break;
        }
    }
    #if LOGGING 
        logClose();
    #endif

    printf("Root is approximately %.10lf + i %.10lf\n", x, y);
    return 0;
}