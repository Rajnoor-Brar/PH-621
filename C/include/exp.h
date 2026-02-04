#pragma once
double expo(double term, int power){
  double val=1; int i;
  if (power==0){val=1;}
  if (power>0){for (i=1;i<=power;i++){val*=term;}}
  if (power<0){for (i=1;i<=-1*power;i++){val*=term;} val=1/val;}
  return val;
}
