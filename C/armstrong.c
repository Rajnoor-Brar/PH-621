#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b;
	printf("Enter the range to find Armstrong numbers \n");
	printf("\t from A = ");scanf("%d",&a);
	printf("\t  to  B = ");scanf("%d", &b);

	int digits[10]={0,1,2,3,4,5,6,7,8,9}, digPower=1; 
		// digit[i] = i^digPower

	int temp,nMax=0;
	if (a>0 && b>0){
		if (b>a){
			temp=b;
		}
		else if(a==b){
			printf("Try again with a RANGE");return -1;
		}
		else if (a>b){
			printf("A should be less than B ... but anyhow ..\n"); 
			temp=a;	a=b;	b=temp;
		}
	}
	else {printf("No negativity or nihilism bro");return -1;}
	while (temp>0){temp=temp/10;nMax++;}

	int i,j,k,p[nMax], nCount=0;
	int *armStrongs = NULL;  
		// pointer to data type INT, pointing to nothing (NULL)

	for (i=a;i<=b;i++){
		j=0;
		temp=i;

		while(temp>0){
				// extract digits of number
			p[j++]=temp%10;  
				// store digits in array p at index j and then increase j (count digits)
			temp/=10;
		}

		if(j>digPower){
				// if power of digits is less than number of digits,
			while(j>digPower){
				for (k=2;k<10;k++){digits[k]*=k;}
				digPower++;
					// then calculate the power of digits until it is equal to number of digits
			}
		}

		temp=0;
		for (k=0;k<j;k++){
			temp+=digits[p[k]];
				// digits[p[k]]] = p[k]^digPower
		}

		if (temp==i){ 
				// if sum of digits raised to power is equal to number, then it is an Armstrong number
			
			nCount++; 
				// increase count of Armstrong numbers found
			
			int *tmp = realloc(armStrongs, nCount * (sizeof *armStrongs)); 
				// reallocate memory (RAM) to accomodate nCount INT values
				// realloc(pointer, newSize) 
				// 	1. allocates new memory of size newSize,
				// 	2. copies the data from pointer of oldSize to new memory. if (newSize>oldSize), remaining bytes are uninitialized
				//     if (newSize<oldSize), extra data is lost.
				//  3. returns pointer to new memory.
			
			if(!tmp){printf("Allocation Error");return -1;} 
				// if allocation fails
			
			armStrongs = tmp; 
				// if successful, point armStrongs to the newly allocated memory
			
			armStrongs[nCount-1]=temp;
				// store latest found Armstrong number at index nCount-1 (since index starts from 0)
		}
	}

	if(nCount==0){
		printf("No Armstrong numbers found between %d and %d \n",a,b);return -1;
	}

	for(i=0;i<nCount;i++){
		if(i==0){
			printf("Armstrong numbers are %d", armStrongs[0]);
		}
		else{
			printf(", %d",armStrongs[i]);
		}
	}
	printf("\n");
	return 0;
}
