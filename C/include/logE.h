#pragma once
double logE(double x){ 

	if (x <= 0.0){printf("\n \t Warning: logE(x) is only defined for positive numbers. \n");return -1;}
        int n=1000,i;
        double precision=1e-10;

        double result=0 , term=(x-1)/(x+1), xx= term*term;

        for (i=1;i<=n;i+=2){
                result += term/i;
                term*=xx;

                if(term<precision){break;}
        }

        return 2*result;

}
