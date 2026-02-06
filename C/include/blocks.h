#define Term_Series(term_modifier)\
do{ \
    	for(i=1;i<=n;i++){ \
		term_modfier \
		result+=term; \
        discontinue = precisionAbort && ( (term<precision && term>0) || (term<0 && term>(-1*precision)) ); \
	        if (discontinue){ \
				NOTICE(PRECISION_REACHED_BREAK,term,precision,i);\
				break; \
			}\
	}\
}\
while(0)