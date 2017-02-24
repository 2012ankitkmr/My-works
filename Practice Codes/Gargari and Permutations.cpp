#include<bits/stdc++.h>
using namespace std;

int n,k;

int dp[1003];
int a[7][1003];
int pos[7][1003];
int ans,maxval,u;
int main()
{
	scanf("%d%d",&n,&k);
	
	for(int i = 1;i<=k;i++)
	{
		for(int j = 1;j<=n;j++)
		{
		scanf("%d",&a[i][j]);
     	pos[i][a[i][j]]=j;
	}
		
	}
ans = INT_MIN ;
for(int i = 1 ; i<=n ; i++)
{
	maxval = 0;
	for(int j = 1;j < i ; j++)
	{
		for(u = 2;u<=k&&((pos[u][a[1][j]])<(pos[u][a[1][i]]));u++);
		if(u==k+1&&dp[j]>maxval)
		maxval = dp[j];
	}
	dp[i] = maxval+1;
	ans = max(ans,dp[i]); 
	
}
printf("%d\n",ans);
	
	return 0;
}
