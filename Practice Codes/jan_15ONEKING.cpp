#include<stdio.h>

int main()
{
	int t,flag;
	bool a[2005];
	long int i,j,n,b;
	for(i=0;i<2005;i++)
	a[i]=0;
	int l[100005],r[100005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		
		for(i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
		
		for(i=l[1];i<=r[1];i++)
		{
			a[i]=1;
		}
		b=1;
		for(i=2;i<=n;i++)
		{
			flag=0;
		  {
		  	for(j=l[i];j<=r[i];j++)
		  	{if(a[j])
		  	{
		  	flag=1;
		  }
		  else
		  a[j]=0;
		  	}	
		  }	
			if(!flag)
		{
		
			for(j=l[i];j<=r[i];j++)
		{
			a[j]=1;
		}
		b++;
	}
		}
		printf("%ld\n",b);
	}
return 0;
}
