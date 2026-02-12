#pragma once
#include"logStream.h"
#include"blocks.h"

double powE(double x){
	int n=100;

	if (x < 0){return (1.0 / powE(-1*x));} // more accuracy this way for negative x

	double result=1,term=1, precision=1e-12;

	Term_Series_PrecisionBreak(
		term,result,precision,1,n,  term=term*x/i;
	);

	return result;
}
