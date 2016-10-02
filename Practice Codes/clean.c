#include<stdio.h>
int main(){
int a,i,b,c,j,k,l,count=0;
scanf("%d",&a);
for(i=0;i<a;i++){
	scanf("%d%d",&b,&c);
	int d[c],p=0;
	for(j=0;j<c;j++){
		scanf("%d",&d[j]);
	}
	k=b-c;
	int e[k];
	
	for(j=1;j<=b;j++){
		int f=0;
		for(l=0;l<k;l++){
			if(d[l]==j){
			f=1;
			break;
		}
		else;
	}
	if(f!=1)	
	{
	e[p]=j;
	p++;
	}	}
	if(k==1){
		count++;
	}
	
	for(j=0;j<k;j+=2)
	printf("%d ",e[j]);		
	
	printf("\n");
	for(j=1;j<k;j+=2)
	printf("%d ",e[j]);
	
	if(count==1)
	printf("\n");	
	
	}

return 0;
}

