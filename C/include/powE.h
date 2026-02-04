#pragma once
double powE(double x){
	int n=100;

	if (x < 0){return (1.0 / powE(-1*x));}

	double result=1,i,term=1, precision=1e-12;

	for(i=1;i<n;i++){
		term=term*x/i;
		result+=term;
		if(term<precision){break;}
	}

	return result;
}
