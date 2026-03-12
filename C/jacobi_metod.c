#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"logStream.h"

int main(){
    int i,j,k=0,n=0;

    #include"linearInput.h"

    double var[n],var_old[n],r=1,precision=1e-6,tmp=0;

    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(coeffs[k][i]<coeffs[j][i]){
                k=j;
            }
        }

        for(j=0;j<=n;j++){
            tmp=coeffs[k][j];
            coeffs[k][j]=coeffs[i][j];
            coeffs[i][j]=tmp;
        }
    }

    k=0,tmp=0;

    for(i=0;i<n;i++){
        var_old[i]=coeffs[i][n]/coeffs[i][i];
    }

    while(r>precision && k<1000){
        r=0;
        for(i=0;i<n;i++){
            var[i]=coeffs[i][n];
            for(j=0;j<n;j++){
                if(i!=j){
                    var[i]-=coeffs[i][j]*var_old[j];
                }
            }
            var[i]/=coeffs[i][i];
        }
        for(i=0;i<n;i++){
            tmp=coeffs[i][n];
            for(j=0;j<n;j++){
                tmp-=coeffs[i][j]*var[j];
            }
            r+=fabs(tmp);

        }

        for(i=0;i<n;i++){
            var_old[i]=var[i];
        }
        k++;
    }

    printf("Solutions are : \n ");
    for ( i = 0; i < n; i++){
        printf("\t x_%d = %lf\n",(i+1),var[i]);
    }
    

}