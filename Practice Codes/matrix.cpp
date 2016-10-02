#include<stdio.h>

int main(){
	long int k,a[1872],r,n,m,i,j;
	long int d,e;
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n*m;i++)
	scanf("%d",&a[i]);

	e=0;
	k=m-1;
	r=n*m;
	while(k--)
	{
		if(k==-1)
		break;

	for(i=k;i<r;i+n)
	{
		for(j=k+1;j<r;j+n)
		{
	d=a[i]*a[j];
	e=e+d;
	printf("%ld\n",e);
	    }
		}	
			
}
	
	printf("%ld",e%10000007);
	return 0;
}
