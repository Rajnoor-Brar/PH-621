#include<stdio.h>
#include "inputMatrix.h"

int main(){
    int i,j,n;
    printf(" Enter size of square matrix N : "); scanf("%d",&n);

    if (n<=0){
        printf("Matrix size should be positive integer\n");
        return -1;
    }

    double matrix[n][n];

    printf("\nEnter elements of matrix A : \n");
    inputMatrix(n,n, matrix);

    printf("\n Result : \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if      (matrix[i][j]>0) { matrix[i][j] *= matrix[i][j]; }
            else if (matrix[i][j]<0) {  matrix[i][j] *= -1;  }
                 else {;}
            printf(" %.4lf ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;

}