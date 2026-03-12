#include <stdio.h>
#include <math.h>
#include "logStream.h"
#include "bisect.h"

#define LOGGING 0

double func(double x){
    return (x*cos(x)-sin(x));
    // return polynomial(1,x);
}

int main() {
//   polynomial(0,0);

  double a,b;
  printf("Enter end points of range to look for:\n");
  scanf("%lf",&a); printf("\033[A\r\033[J %lf to ",a); scanf("%lf",&b);

  bisect(func,a,b);
  return 0;
}
