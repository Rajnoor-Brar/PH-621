#include"logStream.h"
#define Term_Series_PrecisionBreak(term,result,precision,a,n,term_modifier)\
do{ \
    int i, precisionAbort = 1, discontinue = 0;\
    for(i=a;i<=n;i++){ \
    term_modifier \
    result+=term; \
    discontinue = precisionAbort && ( (term<precision && term>0) || (term<0 && term>(-1*precision)) ); \
        if (discontinue){ \
            NOTICE(PRECISION_REACHED_BREAK,term,precision,i);\
            break; \
        }\
	}\
    if (precisionAbort && !discontinue){ WARNING(PRECISION_NOT_REACHED, term, precision ); }\
} while(0)