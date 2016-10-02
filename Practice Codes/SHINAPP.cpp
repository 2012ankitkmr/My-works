#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int t,n,m;
ll dp[303][100005];
ll fact[303];
int main()
{
	scanf("%d",&t);
	fact[0]=1;
	for(int i = 1;i<=300;i++)
	fact[i] = (i*fact[i-1])%MOD;
	
	for(int i =1;i<=300;i++)
	{
		
		for(int j=1;j<=100000;j++)
		{
			if(i==1)
			dp[i][j] = 1;
			else if(j-i>=0)		
			dp[i][j] = (dp[i][j-i] + dp[i-1][j-i])%MOD;
		}
	}
	

ll ans;
	while(t--)
	{
	scanf("%d%d",&n,&m);
	
	ans = (dp[n][m]*fact[n])%MOD;
	printf("%lld\n",ans);

}
	return  0;
}
