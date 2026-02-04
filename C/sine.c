#include <stdio.h>
#include "sine.h"

int main() {
  double x;int acc;
  printf("Enter the accuracy as numbers of terms : ");
scanf("%d",&acc);
  printf("Enter value : ");scanf("%lf", &x);
  printf("Sin(%.4lf) is %.6lf\n",x,sine(x,acc));
  return 0;
}

