#include<stdio.h>
#include<string.h>

int main()
{
	int i,sum1,sum2,t,n,m,k,temp;
	int b1[105],b2[105];
	for(scanf("%d",&t);t--;)
{
	memset(b1,0,sizeof b1);
	memset(b1,0,sizeof b2);
	scanf("%d%d%d",&n,&m,&k);
	
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
	b1[temp]=1;
	}

	for(i=0;i<k;i++)
	{
		scanf("%d",&temp);
	b2[temp]=1;
	}	
	for(i=1;i<=n;i++)
	printf("b2[%d]=%d\n",i,b2[i]);
	sum1=0;
	for(i=1;i<=n;i++)
	{
		if(b1[i]==1&&b2[i]==1)
		{
		sum1++;
	//printf("i=%d\n",i);
	}
	}
	sum2=0;
	for(i=1;i<=n;i++)
	{
		if(b1[i]==0&&b2[i]==0)
		sum2++;
	}
printf("%d %d\n",sum1,sum2);	
}	
	return 0;
}
