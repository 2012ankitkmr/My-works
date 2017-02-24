#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair 

vector<int,pair<int,int> > g[5003];
int n,m,T,a,b,c;


int compute(int pos,int num,int cost)
{
	if(pos==n)
	return num;
	
	if(cost<=0)
	return INT_MIN;
	
	if(dp[pos][num]!=-1)
	return dp[pos][num];	
	int ans = INT_MIN,am;
	pair<int,int>to;
	for(int i = 0;i<g[pos].size();i++)
	{
		to = g[pos][i];
		node = to.first;
		am = to.second;
		ans = max(ans,compute(node,num+1,cost-am));	
		
	}
	return dp[pos][num]=ans;
	
}

int main()
{


scanf("%d%d%d",&n,&m,&T);

for(int i = 0;i<m;i++)
{
	scanf("%d%d%d",&a,&b,&c);
	g[a].pb(mp(b,c));
	g[b].pb(mp(a,c));
}

memset(dp,-1,sizeof dp);
cout<<compute(1,0,T);
	
	return 0;
}
