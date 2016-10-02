#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a) < (b) ? a : b)
int main(){
	int d,t,n,a[40][2],i,c,e,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	b=n-1;
	e=1;
	while(b--)
	{
		d=1001;
		for(i=2;i<=n;i++)
		{
		if(d>(min((abs(a[1][0]-a[i][0])),(abs(a[1][1]-a[i][1])))))	
		{
		d=min((abs(a[1][0]-a[i][0])),(abs(a[1][1]-a[i][1])));
		c=i;
		
	}
	
		}	
		printf("%d\n",d);
		a[c][0]=3500;
		a[c][1]=3500;	
		
		e=e^c;
}
printf("%d\n",e);
	}
	return 0;
}
