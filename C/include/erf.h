#pragma once
#include"logStream.h"
#include"blocks.h"

double erf(double x, int n){
    double result=0,term=1;
	int i, precisionAbort = 1, discontinue = 0;

	double xx = x*x, precision=1e-8;
	result = x; term = x;

    Term_Series_PrecisionBreak(term,result,precision,1,n, 
		term *= (-1*xx*(2*i-1)/((2*i+1)*i));
	);

	result *= 1.1283791670955126; // 2/sqrt(pi) = 1.1283791670955126

    return result;
}