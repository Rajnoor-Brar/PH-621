#include<stdio.h>
#include<stdlib.h>
#include "inputMatrix.h"
#include "logStream.h"

int main(){
    int i,j,m,n, positiveCount=0, negativeCount=0, zeroCount=0;
    printf(" Enter size of matrix N : "); scanf("%d",&n);
    printf("\033[A\r\033[J Enter size of matrix %d x M : ",n);scanf("%d",&m);
    printf("\033[A\r\033[J Enter size of matrix %d x %d",n,m);

    if (n<=0 || m<0){
        NOTICE(POSITIVE_DOMAIN);   // Only Error is important, Warning and Notice
        WARNING(POSITIVE_DOMAIN);  // are just put to suppress "Function Unused" warnings
        ERROR(POSITIVE_DOMAIN);    // during compilation
        exit(1);
    }

    double matrix[n][m];

    printf("\nEnter elements of matrix A : \n");
    inputMatrix(n,m, matrix);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            (matrix[i][j]>0) ? positiveCount++ : ((matrix[i][j]==0) ? zeroCount++ : negativeCount++);
        }
    }

    printf("\n Matrix Statistics \n");
    printf("Positive elements : %d\n", positiveCount);
    printf("Negative elements : %d\n", negativeCount);
    printf("  Zero   elements : %d\n", zeroCount);

    return 0;

}