#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,b;	
int a[502];
int mod;
int dp[2][502][502];

int main()
{
	scanf("%d%d%d",&n,&m,&b);
	cin>>mod;
	memset(dp,-1,sizeof dp);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	dp[0][0][0]=1;
	for(int it = 1;it<=n;it++)
	{
		it =i^1;
		for(int j = 0;j<=m;j++)
		{
			for(int k = 0;k<=b;k++ )
			{
				dp[i][j][k] = dp[i^1][j][k];
				 if (j > 0 && k >= a[it - 1])
				  dp[i][j][k] = (dp[i][j][]+dp[i][j - 1][k - a[it - 1]])%mod;
				  
			}
			
			
		}
		
	}
	
	
	return 0;
}
