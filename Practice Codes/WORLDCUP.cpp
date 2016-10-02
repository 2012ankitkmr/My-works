#include<bits/stdc++.h>
using namespace std;
#define MOD (long long)1000000007
long long dp[1850][305][11];

long long compute(int runs,int balls,int wicket)
{
	if(balls==0)
	{
		if(runs==0)
		return 1;
		return 0;
	}	
	if(runs>balls*6)
	return 0;
if(dp[runs][balls][wicket]!=-1)
return dp[runs][balls][wicket];

long long ans=0;
//printf("%d,%d,%d\n",runs,balls,wicket);
if(runs>=6)
{
ans=ans+compute(runs-6,balls-1,wicket);
ans%=MOD;
}
if(runs>=4)
{
ans=ans+compute(runs-4,balls-1,wicket);
ans%=MOD;	
}
if(6*(balls-1)>=runs)
{
ans=ans+compute(runs,balls-1,wicket);
ans%=MOD;
}
if(6*(balls-1)>=runs)
if(wicket>0)
{
ans=ans+compute(runs,balls-1,wicket-1);
ans%=MOD;
}
	return dp[runs][balls][wicket]=ans;
}
int main()
{
	int test,r,b,w;
memset(dp,-1,sizeof dp);	
	for(scanf("%d",&test);test--;)
	{
	scanf("%d%d%d",&r,&b,&w);
	if(r>b*6)
	{
	printf("0\n");	
	}
	else if(r&1)
	{
		printf("0\n");
	}
	else
	{
		if(dp[r][b][w]!=-1)
		printf("%lld\n",dp[r][b][w]);
		else
		printf("%lld\n",compute(r,b,w));
	}		
	}
	return  0;
}
