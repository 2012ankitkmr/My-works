#include<stdio.h>
int main(){
	
	int t,i,j,k,p,q,f;
	long unsigned int avg,c;
	scanf("%d",&t);
	long unsigned int a[t];
	scanf("%d",&avg);
	double d;
	for(i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<t;i++){
		c=0;
		k=1;
		for(j=i;j<t;j++){
		c=c+a[j];
			d=c/k;
		p=k;
			if(d==avg){
			q=i+1;
			f=0;
			break;	
			}
			k++;
		
		}		
	}
	p=p+q;
	if(f==0)
	printf("%d %d",q,p);
	else
	printf("%d",-1);
return 0;	
}
