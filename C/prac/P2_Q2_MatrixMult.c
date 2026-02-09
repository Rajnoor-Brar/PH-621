#include<stdio.h>
#include<stdlib.h>
#include "u_inputMatrix.h"
#include "u_logStream.h"

int main(){
    int i,j,k,n;
    printf("Enter size of square matrices, n : ");
    scanf("%d",&n);

    if (n<=0){
        NOTICE(POSITIVE_DOMAIN);   // Only Error is important, Warning and Notice
        WARNING(POSITIVE_DOMAIN);  // are just put to suppress "Function Unused" warnings
        ERROR(POSITIVE_DOMAIN);    // during compilation. Not ideal but ehh too much headache
        exit(1);                   // to deal with
    }

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