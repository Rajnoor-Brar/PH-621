#include<stdio.h>
#include<stdlib.h>
#include "inputMatrix.h"
#include "logStream.h"

int main(){
    int i,j,k,n;
    printf("Enter size of square matrices, n : ");
    scanf("%d",&n);

    if (n<=0){ERROR(POSITIVE_DOMAIN); exit(1);}

    double matrixA[n][n],matrixB[n][n], answer[n][n];

    printf("\nEnter elements of matrix A : \n");
    inputMatrix(n,n, matrixA);

    printf("\nEnter elements of matrix B : \n");
    inputMatrix(n,n, matrixB);

    printf("\nAnswer (A x B) : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           answer[i][j]=0;

           for(k=0;k<n;k++){
               answer[i][j] += matrixA[i][k]*matrixB[k][j];
           }
           printf(" %.4lf ",answer[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}