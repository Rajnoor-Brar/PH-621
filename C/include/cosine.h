#include <stdio.h>
#include "exp.h"
#include "fac.h"

double preprocess4cosine(double x){
  double pi=3.141592653589793;

  if (x<0){x=-1*x;}                                    // cos(-x) = cos(x)

//Reduction of x beyond 2π
  while(x>=(2*pi)) {x-=2*pi;}

//Reduction of x between {2π, π}
  if(x>=pi) {x=2*pi-x;}                                  // cos(2π-x) = cos x  for  2π > x > 0

  return x;
}

double cosine(double x,int acc){
  double val=1,term=1;
  int i,j;

  x=preprocess4cosine(x);
  double x2=x*x;
  for (i=1; i<acc; i++)  {
    j=2*i;
    term *= -1*(x2/(j*(j-1)));
    val+=term;
  }
  return val;
}
