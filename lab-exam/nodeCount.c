#include<stdio.h>
#include<math.h>
#define BOXLENGTH 5
int main(){
	int i,n=10,count=0;

	double x=0,k=0,y=0,interval=0.0001, boxLeft=0.05, length=BOXLENGTH,boxRight=BOXLENGTH-0.05, precision=1e-3, a0=sqrt(2/length), pi=3.141592, nullX=0;
	FILE* stateLog = NULL;
	FILE* log = fopen("nodeCount.dat","w");
	if(log==NULL){printf("file error");return 0;}

	char excitedName[50];

	for(i=1;i<=n+1;i++){
		if (stateLog!=NULL){fclose(stateLog); stateLog=NULL;}
		snprintf(excitedName, sizeof excitedName, "excited_%02d.dat",i-1);
		stateLog = fopen(excitedName,"w");
		if(stateLog==NULL){printf("file error");return 0;}

		count=0;
		k=i*pi/length;
		for(x=boxLeft;x<boxRight;x+=interval){
                	y=a0*sin(k*x);
			fprintf(stateLog," %08.6lf | %09.6lf \n",x,y);

			if(fabs(y)<precision && fabs(x-nullX)>=length/(4*i)){count++;nullX=x;}
        	}

		printf(" %02d  %02d \n",i-1,count);
                fprintf(log," %02d  %02d \n",i-1,count);

		fclose(stateLog);
		stateLog = NULL;
	}

	fclose(log);
	log=NULL;

	return 0;
}
