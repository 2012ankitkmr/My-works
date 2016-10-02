#include<bits/stdc++.h>
using namespace std;
#define  D 0

long long max(long long a,long long b)
{
	return a>b?a:b;
}
long long dp[50004][6],paint[50004][6];
int main()
{
	for(int i = 0;i<6;i++)
	dp[0][i]=0;
	int m,n;
	scanf("%d%d",&m,&n);
	
	for(int i = 1 ; i<=m ; i++)
	{
		for(int j = 1 ; j<=n ; j++)
		{
cin>>paint[i][j];
		}
	}
	
	dp[1][1]=paint[1][1];
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1 ; j<=m;j++)
		{
			if(i==1&&j==1)
			continue;
			
			dp[j][i] = max(dp[j-1][i],dp[j][i-1])+paint[j][i];
			if(D)
			cout<<dp[j][i]<<" ";
		}
		if(D)
		cout<<endl;
	}
for(int i=1;i<=m;i++)
cout<<dp[i][n]<<" ";
	
	return  0;
}
