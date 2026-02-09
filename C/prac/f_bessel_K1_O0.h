#pragma once
double bessel_K1_O0(double x, int n){
	int i;

	double result = 1, xx = (x*x)/4;

	// Using Horner's Method
	for(i=n-1;i>0;i-=1){
		result = 1 - ((result * xx) / (i*i));
	}
	return result;
}