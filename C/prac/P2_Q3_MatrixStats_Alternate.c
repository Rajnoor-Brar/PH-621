#include<stdio.h>

int main(){
    int i,j,m,n, positiveCount=0, negativeCount=0, zeroCount=0;
    printf(" Enter size of matrix N : "); scanf("%d",&n);
    printf("\033[A\r\033[J Enter size of matrix %d x M : ",n);scanf("%d",&m);
    printf("\033[A\r\033[J Enter size of matrix %d x %d",n,m);

    double element=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf(" Enter element [%d][%d] : ",i,j);
            scanf("%lf",&element);
            (element>0) ? positiveCount++ : ((element==0) ? zeroCount++ : negativeCount++);
        }
    }

    printf("\n Matrix Statistics \n");
    printf("Positive elements : %d\n", positiveCount);
    printf("Negative elements : %d\n", negativeCount);
    printf("  Zero   elements : %d\n", zeroCount);

    return 0;

}