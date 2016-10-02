#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,i,r,b,g,m,j;
	scanf("%d",&t);
		long unsigned int R[100],G[100],B[100];
	for(i=0;i<t;i++){

		scanf("%d%d%d",&r,&g,&b,&m);
	
		for(j=0;j<r;j++){
		scanf("%ld",&all[j]);
		}

		j=c-1;
		while(m>0){
			all[j]=all[j]/2;

			m--;
		}
		printf("%d",all[j]);
			}
		return 0;
	}



