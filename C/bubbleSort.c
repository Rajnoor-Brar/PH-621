#include<stdio.h>

int main(){
    int count;
    printf("Number of elements to sort: ");scanf("%d",&count);
    int i,number[count];

    for (i=0;i<count;i++){
        printf("\b Enter element %d: ",i+1);scanf("%d",&number[i]);
    }

    int j, temp;
    for (i=0;i<count-1;i++){
        for(j=i;j<count;j++){
            if(number[i]>number[j]){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i=0;i<count;i++){
        printf("%d ",number[i]);
    }
    printf("\n");
    return 0;
}