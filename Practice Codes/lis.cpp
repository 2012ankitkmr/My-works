#include<bits/stdc++.h>

int a[5000];
int dp[5000];

int lis(int n)
{
	int i,j,max=0;
	for(i=0;i<=n;i++)
	dp[i]=1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j]&&dp[i]<dp[j]+1)
			dp[i]=dp[j]+1;
		}
	}
	for(i=0;i<n;i++)
	if(max<dp[i])
	max=dp[i];
	
	return max;
	
}
int main()
{
	int t,n,i;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		printf("ans=%d\n",lis(n));
	}
	return 0;
}
