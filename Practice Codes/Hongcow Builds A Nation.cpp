#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool g[1003][1003];

bool vis[1003];
vector<ll>vec;
ll cntedge[1003];
ll col[1003];
	ll n,m,k,a;

ll dfs(ll u,ll c)
{
	col[u]=c;
	vis[u]=1;
	ll ans=1;
	for(ll i =1;i<=n;i++)
	{
		if(g[u][i]==1)
		if(!vis[i])
		ans = ans+dfs(i,c);
	}
	return ans;
}
bool imp[1003];
bool has[1003];
ll x[1003],y[1003],color;
int main()
{
	
	cin>>n>>m>>k;
	for(ll i = 0;i<k;i++)
	{
cin>>a;
	has[a]=1;
    }
    for(ll i = 0;i<m;i++)
    {
    	scanf("%I64d%I64d",&x[i],&y[i]);
    	g[x[i]][y[i]]=1;
    	g[y[i]][x[i]]=1;
    	if(n==1000)
    	if(has[x[i]]||has[y[i]])
    	printf("ggg\n");
    }
    
    color=0;
    vec.pb(0);
    for(ll i = 1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		color++;
    		vec.pb(dfs(i,color));
    		if(has[i])
    		imp[color]=1;
    		if(n==1000)
    		printf("here\n");
    	}
    }
    for(ll i =0;i<m;i++)
	{
	cntedge[col[x[i]]]++;
    if(has[x[i]]||has[y[i]])
    {
    	imp[col[x[i]]]=1;
    	if(n==1000)
    	printf("here2\n");
    }
    
	}
	
	long long ans = 0;
	ll maxcol = -1,ind = -1;
	for(ll i = 1 ; i <= color ; i++)
	{
		if(imp[i])
			if(maxcol < vec[i])
			{
				maxcol = vec[i];
				ind = i;
			}
	}
	ll sumed = 0,sumno=0;
	int fl=0;
	for(ll i = 1 ; i <= color ; i++)
	{
		ll numnode = vec[i];
		if(imp[i])
		ans = ans + ((numnode*(numnode-1))/2) - cntedge[i];
		else
		{
			fl=1;
			sumed+=cntedge[i];
			sumno+=numnode;
		//	cout<<i;
		}
		
	}
if(n==1000)
	cout<<sumno<<maxcol<<color<<ans;
    if(fl)
	ans= ans+(((sumno+maxcol)*(sumno+maxcol-1))/2) - sumed - ((maxcol*(maxcol-1))/2);
	cout<<ans;
	return 0;
}
