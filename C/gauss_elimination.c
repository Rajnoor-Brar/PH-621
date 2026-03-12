#include<stdio.h>
#include<math.h>

int main(){
    int i,j,k,n;
    double tmp;

    #include"linearInput.h"

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            tmp=coeffs[j][i]/coeffs[i][i];
            for(k=0;k<=n;k++){
                coeffs[j][k]-=tmp*coeffs[i][k];
            }
        }
    }

    // printf("\n");
    //     for(i=0;i<n;i++){
    //     for(j=0;j<=n;j++){
    //         printf(" %lf ",coeffs[i][j]);
    //     }
    //     printf("\n");
    // }

    double vars[n];

    vars[n-1]=coeffs[n-1][n]/coeffs[n-1][n-1];

    for(i=n-2;i>=0;i--){
        vars[i]=coeffs[i][n];
        for(j=i+1;j<n;j++){
            vars[i]-=coeffs[i][j]*vars[j];
        }
        vars[i]/=coeffs[i][i];
    }

    printf("Solutions are : \n ");
    for ( i = 0; i < n; i++){
        printf("\t x_%d = %lf\n",(i+1),vars[i]);
    }

}