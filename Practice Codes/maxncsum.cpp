#include<bits/stdc++.h>
int a[5000];

int maxncsum(int n)
{
	int i,dp[n+1];
	dp[0]=a[0];
	dp[1]=a[0]>a[1]?a[0]:a[1];
	for(i=2;i<n;i++)
	dp[i]=(dp[i-1]>dp[i-2]+a[i]?dp[i-1]:dp[i-2]+a[i]);
	return dp[n-1];
}

int main()
{
	int t,n,i;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);

for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
printf("maxsum=%d\n",maxncsum(n));
	}
	return 0;
}


