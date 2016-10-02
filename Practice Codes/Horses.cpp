#include<stdio.h>

int main()
{
	int t,n,j,k;
	scanf("%d",&t);
	long int d;
	long unsigned int s[5000],e;
	while(t--)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		scanf("%lu",&s[j]);
		e=s[1]-s[0];
		if(e<0)
		e*=(-1);
		for(j=0;j<n;j++)
		{
		   for(k=0;k<n;k++)
		   {if(k!=j)
		   	d=s[j]-s[k];
		   	
		   	if(d<0)
		   	d*=(-1);
		   	
			   if(e>d)
		   	   e=d;
		   }
		}
		
		printf("%lu\n",e);
	}
	return 0;
}
