#include <stdio.h>
#include "cosine.h"

int main() {
  double x;int acc;
  printf("Enter the accuracy as numbers of terms : ");
  scanf("%d",&acc);
  printf("Enter value : ");scanf("%lf", &x);
  printf("Cos(%.4lf) is %.6lf\n",x,cosine(x,acc));
  return 0;
}
