#include<stdio.h>

int main()
{
	int t,q;
	
	long int n,i,count,a[100005],d[1000000005],l,r,res,j,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		
		for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
		
		
		for(m=0;m<n;m++)
		{
		for(j=m;j<n;j++)
		{res=0;
			for(i=m;i<=j;i++)
			{
			res^=a[i];
		}
		  d[res]++;		
	        }
	        }
		scanf("%d",&q);
		
		while(q--)
		{
		scanf("%ld%ld",&l,&r);
		count=0;
		for(i=l;i<=r;i++)
		count=count+d[i];
		
		printf("%ld\n",count);	
		}
	}
	return 0;
}
