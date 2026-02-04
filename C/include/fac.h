#pragma once
double fac(int x){
  int i; 
  double val=1;
  for (i=1;i<=x;i++) {val*=i;} 
  return val;
}
