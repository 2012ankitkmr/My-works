#include<stdio.h>
#include<stdlib.h>


int main(){
	int a,i,flag;
	long unsigned int b,j,k,count;
	long int*ptr;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&b);
				count=0;
				ptr=(long int*)calloc(b,sizeof(long int));
		for(j=0;j<b;j++){
			scanf("%d",ptr+j);
		}		
		flag=0;
		for(j=0;j<b;j++){
			for(k=j+1;k<b;k++)
			{if((*ptr+j)==(*ptr+k)*(-1)){
				count++;
				(*ptr+k)=(float)1.2;
				break;
				
			}
			}
		flag=0;	
		}
		printf("%d\n",count);
		
	}
	return 0;
}
