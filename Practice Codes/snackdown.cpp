#include<bits/stdc++.h>

int main()
{
	int ans[55],b[55];
	int t,c[55],n,i,flag,sum,counter,j,temp;
	for(scanf("%d",&t);t--;)
{
	scanf("%d",&n);
	flag=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
	scanf("%d",&c[i]);
		
	sum=sum+c[i];
	if(sum>n)
{//printf("sum=%d,n=%d\n",sum,n);
	flag=1;		
}
	if(c[i]==n)
	{
	flag=1;
}

	}
	if(flag)
	printf("-1\n");
	else
	{
		memset(ans,0,sizeof ans);
		memset(b,0,sizeof b);
		counter=0;
		temp=0;
		j=0;
		for(i=1;i<=n;i++)
		{
			j=0;
		  while(c[i]--)
		{
			j++;
			if(j!=i&&!b[j])
			b[j]=1;
			else
			c[i]++;
		}
			ans[i]=j;
		}
	
		for(i=1;i<=n;i++)
	printf("%d ",ans[i]);
	}
	printf("\n");
}	
return 0;
}
