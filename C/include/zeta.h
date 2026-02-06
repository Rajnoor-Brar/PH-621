#pragma once

#include"logE.h"
#include"powE.h"
#include<stdio.h>
#include"logStream.h"

double zeta(double s, int maxTerms){
    int i,n, precisionAbort = 1, discontinue = 0;
    (maxTerms<=0) ? (n=200) : (n=maxTerms); // default maxTerms = 200

	double precision=1e-12 , ex =0, term, ns  = -1*s, result = 0;

	for(i=1;i<=n;i++){
		ex   = ns*logE(i);
		term = powE(ex);
		result+=term;

        discontinue = precisionAbort && ( (term<precision && term>0) || (term<0 && term>(-1*precision)) );
	        if (discontinue){
				NOTICE(PRECISION_REACHED_BREAK,term,precision,i);
				break;
			}
	}

	if (precisionAbort && !discontinue){ WARNING(PRECISION_NOT_REACHED, term, precision ); }

	return result;
}
