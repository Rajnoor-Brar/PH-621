#include "exp.h"
#include "fac.h"

double preprocess4sine(double x){
  double pi=3.141592653589793;

//Reduction of x beyond {-2π,2π}
  while(x>=(2*pi)) {x-=2*pi;}
  while(x<=(-2*pi)) {x+=2*pi;}

//Reduction of x between {2π, π}
  if(x>=pi) {x=pi-x;}                                  // sin(π-x) = sin x                ,  2π >x> 0
  if(x<=-1*pi)  {x=-1*(pi+x);}                         // sin(-π-x) = sin x               , -2π <x< 0

//Reduction of x between {π, π/2}
  if(x>pi/2 && x<=pi) {x=pi-x;}                       // sin(π-x) = sin(x)                ,  π> x> 0
  if(-1*x>pi/2 && -1*x<=pi) {x=-1*(pi+x);}            // sin(-π-x) = sin (x)              , -π <x< 0

  return x;
}

double sine(double x,int acc){
  double val=0,term=0;
  int i,j;

  x=preprocess4sine(x);
  double x2=x*x;
  val=x;term=x;

  for (i=2; i<=acc; i++)  {
    j=2*i-1;
    term *= -1*(x2/(j*(j-1)));
    val+=term;
  }
  return val;
}
