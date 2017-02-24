#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long 
int n,m,k;
int adj[12][12];
ll dp[12][90][810];
int sq[12];
ll compute(int pos,int sum,int sqsum,int prev)
{
	if(pos==n)
	{
		if((sum%m==0)&&(sqsum%m==0))
		{		
		return 1;
    	}
		else
		return 0;
	}
	if(dp[pos][sum][sqsum]!=-1)
	return dp[pos][sum][sqsum];
	ll ans=0;
	for(int i= 0;i<=9;i++)
	{
		if(!adj[prev][i])
		{
			if(pos==0&&i==0)
			continue;
			ans =(ans+compute(pos+1,(10*sum+i)%m,sqsum+sq[i],i))%MOD;
		}

	}
	return dp[pos][sum][sqsum]=ans;
}

int main()
{
	for(int i = 0;i<=9;i++)
	sq[i]=i*i;
	
	int t,a,b;
	ll ans;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i  =0; i < k ;i++)
		{
			scanf("%d%d",&a,&b);
			adj[a][b]=1;
			adj[b][a]=1;
		}
		memset(dp,-1,sizeof dp);
		
		ans = compute(0,0,0,10);
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}
