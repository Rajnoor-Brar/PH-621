#include <stdio.h>
#include <math.h>
#include "logStream.h"

#define LOGGING 0

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
    double x=30,y=32,f_u,f_v,f_ux,f_uy,f_vx,f_vy,f_J, precision=1e-12;
    int maxIter=10000, iter=0;

    #if LOGGING 
        logInitialise("newton_raphson_complex");
    #endif
    f_u = u(x,y); f_v = v(x,y); f_ux = u_x(x,y); f_uy = u_y(x,y); f_vx = v_x(x,y); f_vy = v_y(x,y);

    while(fabs(f_u)>precision && fabs(f_v)>precision){
        f_J = J(x,y);
    
        x -= (f_u*f_vy - f_v*f_uy)/f_J;
        y -= (f_v*f_ux - f_u*f_vx)/f_J;
        f_u = u(x,y); f_v = v(x,y); 
        f_ux = u_x(x,y); f_uy = u_y(x,y);
        f_vx = v_x(x,y); f_vy = v_y(x,y);

        #if LOGGING 
            streamLog(" %*.*lf + i %*.*lf | %*.*lf + i %*.*lf\n", 20,12,x,20,12,y, 20,12,f_u, 20,12,f_v);
        #endif
        if(++iter>=maxIter){
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