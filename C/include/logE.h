#include"logStream.h"
#include<stdlib.h>
#include"blocks.h"

#pragma once
double logE(double x){ 

	if (x <= 0.0){ERROR(POSITIVE_DOMAIN); exit(1);} 

        int n=200,j;
        double precision=1e-12, ln2=0.6931471805599453;
        int pow2=0;

                // ln (x) = ln(x/2^k) + k ln(2)
        while(x>2){ x/=2; pow2++;}
        while(x<0.5){ x*=2; pow2--;}
                // series is most accurate for small x, but too close to 0 is also risky
                // x is scaled to [0.5, 2]

        double term=(x-1)/(x+1), xx= term*term, result=term;

        Term_Series_PrecisionBreak(term, result,2,n, precision,
                j=2*i-1;
                term*=xx/j;
        );

        return ((2*result)+(ln2*pow2));
}
