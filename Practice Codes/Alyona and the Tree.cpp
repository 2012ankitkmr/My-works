#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int n,p;
ll a[100005],c;
vector<pair<int,ll> >gph[100005];
ll sum[100005];
	bool visited[100005];

void fillsum()
{
	memset(visited,0,sizeof visited);
	queue<int>q;
	q.push(1);
	int b;
	sum[1]=0;
	visited[1]=1;
	while(!q.empty())
	{
		b = q.front();
		q.pop();
		for(int i = 0;i<gph[b].size();i++)
		{
			
			pair<int,ll>temp = gph[b][i];
			
	
			if(!visited[temp.fi])
			{
			//			printf("%d\n",temp.fi);
				q.push(temp.fi);
				visited[temp.fi]=1;				
			    sum[temp.fi] = sum[b]+temp.se;
			}
		}
		
	}
}

int dfs(int u,ll mini,int prev)
{

if(prev==1)
{
if(sum[u]-0>a[u])
return 0;
}
if(sum[u]-mini>a[u])
return 0;
//printf("%d %lld\n",u,mini);

int ans = 1;
for(int i =0;i<gph[u].size();i++)
{
	pair<int,ll>temp = gph[u][i];
	if(!visited[temp.first])
	{
		visited[temp.first]=1;		
    	ans +=  dfs(temp.fi,min(mini,sum[u]),u);	
	}
	
} 

	return ans;
	
}

int main()
{
//	freopen("in.txt","r+",stdin);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	scanf("%I64d",&a[i]);
	
	for(int i = 1;i<=n-1;i++)
	{
	scanf("%d%I64d",&p,&c);
	gph[i+1].push_back(make_pair(p,c));
	gph[p].push_back(make_pair(i+1,c));
	}
	
	fillsum();
//	for(int i = 1;i<=n;i++)
//	printf("%lld ",sum[i]);
//	printf("\n");
sum[1]=0;
	memset(visited,0,sizeof visited);
	visited[1]=1;
	int ans = dfs(1,100000000000000,0);
	cout<<n-ans;
return 0;
}
