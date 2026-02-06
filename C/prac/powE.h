#pragma once
#include"logStream.h"

double powE(double x){
	int i, n=100, precisionAbort = 1, discontinue;

	if (x < 0){return (1.0 / powE(-1*x));} // more accuracy this way for negative x

	double result=1,term=1, precision=1e-12;

	for(i=1;i<n;i++){
		term=term*x/i;
		result+=term;

		discontinue = precisionAbort && ( (term<precision && term>=0) || (term<0 && term>(-1*precision)) );
		if(discontinue){NOTICE(PRECISION_REACHED_BREAK,term,precision,i); break;}
	}
	if (precisionAbort && !discontinue){ WARNING(PRECISION_NOT_REACHED, term, precision); }

	return result;
}
