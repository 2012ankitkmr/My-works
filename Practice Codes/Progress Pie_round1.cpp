#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[302][302];
	int t,tot,n,m;

bool comp(const ll &x,const ll &y)
{
	return x<=y;
}

ll dp[302][302];
ll compute(int pos,int totpie,ll cost,int cur)
{

if(pos==n)
return cost;
if(dp[pos][totpie] != -1)
return dp[pos][totpie];
	
	ll ans = 1e15;
	int i = 0;
	if(totpie <= pos)
	{
	cost += a[pos][0];
	i++;
	}
	ll sum=0;
	ans = min(ans,compute(pos+1,totpie+i,cost+i*i,i));
	for(;i<m;i++)
	{
		if((totpie+i+1)>n)
		break;
		sum += a[pos][i];
		
		ans = min(ans , compute( pos + 1 , totpie + i + 1 , cost + sum + (i+1)*(i+1),i+1));
		
	}
return dp[pos][totpie]=ans;
return ans;
}

int main()
{
	freopen("in.txt","r+",stdin);
	ll ans;
	scanf("%d",&t);
	for(int test = 1 ; test <= t ; test++)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				scanf("%lld",&a[i][j]);
			}
			sort(a[i],a[i]+m);
		
		}
memset(dp,-1,sizeof dp);
	printf("Case #%d: %lld\n",test,compute(0,0,0,0));	

}
	
	return  0;
}
