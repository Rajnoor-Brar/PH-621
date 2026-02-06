#pragma once
#include"logStream.h"

double erf(double x, int n){
    double result=0,term=1;
	int i, precisionAbort = 1, discontinue = 0;

	double xx = x*x, precision=1e-8;
	result = x; term = x;

	for (i=1;i<n;i++){
		term *= (-1*xx*(2*i-1)/((2*i+1)*i));
		result += term;

        discontinue = precisionAbort && ( (term<precision && term>=0) || (term<0 && term>(-1*precision)) );
                
		if ( discontinue ){
			NOTICE(PRECISION_REACHED_BREAK,term,precision,i);break;
		}
	}
	if ( (term>precision && term>0) || (term<0 && term<(-1*precision)) ){
		WARNING(PRECISION_NOT_REACHED, term, precision);
	}

	result *= 1.1283791670955126; // 2/sqrt(pi) = 1.1283791670955126

    return result;
}