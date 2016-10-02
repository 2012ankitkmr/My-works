#include<bits/stdc++.h>
using namespace std;
int dp[13][100];
 int compute(int n,int k)
 {
 	if(n==0)
 	return 0;
 	if(k==0)
 	return 1;
 	if(dp[n][k]!=-1)
 	return dp[n][k];
 	int val=0;
 	for(int i=0;i<n&&k-i>=0;i++)
 	{
 		val+=compute(n-1,k-i);
 	}
 	return dp[n][k]=val;
 }

int main()
{
	int t,n,k;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&k);
		memset(dp,-1,sizeof dp);
		printf("%d\n",compute(n,k));
	}
	return 0;
}
