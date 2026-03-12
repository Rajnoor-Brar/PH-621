#include<stdio.h>
#include<math.h>

int main(){
    int i,j,k,l,n;

    #include"linearInput.h"
printf("\n");
    double lower[n][n],upper[n][n];
    for(l=1;l<=n;l++){
        upper[l][l]=1;
    }
    for(l=0;l<=n-1;l++){
        for(i=l;i<=n-1;i++){
            lower[i][l]=coeffs[i][l];
            for(k=0;k<l-1;k++){
                lower[i][l]-=lower[i][k]*upper[k][l];
            }
        }

        for(j=l;j<=n-1;j++){
            upper[l][j]=coeffs[l][j];
            for(k=0;k<l-1;k++){
                upper[l][j]-=lower[l][k]*upper[k][j];
            }
            upper[l][j]/=lower[l][l];
        }
    }

    for(l=0;l<=n-1;l++){
        for(i=1;i<l;i++){
            lower[i][l]=0;
            upper[l][i]=0;
        }
    }
printf("\n");
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            printf(" %10.4lf ",lower[i][j]);
        }
        printf("\n");
    }
printf("\n");
    for(i=0;i<=n-1;i++){
        for(j=0;j<=n-1;j++){
            printf(" %10.4lf ",upper[i][j]);
        }
        printf("\n");
    }

    // printf("Solutions are : \n ");
    // for ( i = 0; i < n; i++){
    //     printf("\t x_%d = %lf\n",(i+1),vars[i]);
    // }

}