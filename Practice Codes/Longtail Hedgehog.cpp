#include<bits/stdc++.h>
using namespace std;


vector<int>graph[100005];
long long dp[100005];

int a,b;
int main()
{
//	freopen("in.txt","r+",stdin);
	int n,m;
scanf("%d%d",&n,&m);

for(int i =0 ; i < m ; i++)
{
	scanf("%d%d",&a,&b);
	graph[a].push_back(b);
	graph[b].push_back(a);
}
for(int i = 1 ; i<=n;i++)
{
	dp[i]=1;
for(int j = 0;j<graph[i].size();j++)
	{
		int v = graph[i][j];
		if(v<i)
		dp[i] = max(dp[i],1+dp[v]);
	}
	
//	printf("%lld\n",dp[i]);
}


long long ans = -1;
for(int i = 1;i<=n;i++)
{
	ans = max(ans,dp[i]*(long long)graph[i].size());
}
	cout<<ans<<endl;
	return 0;
}
