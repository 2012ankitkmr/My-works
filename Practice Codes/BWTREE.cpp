#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long sum(long long num)
{
 num = num*(num+1);
return num/2;
}

long long cnt;

vector<int>graph[100005];
int color[100005];

int visited[100005];

char ch;
void dfs(int a,int col)
{
	if(col!=color[a])
	return ;
	visited[a]=1;
	cnt++;
	//printf("%lld\n",cnt);
	for(int i =0;i<graph[a].size();i++)
	{
		if((!visited[graph[a][i]]))
		{
			//	cout<<graph[a][i]<<endl;
			dfs(graph[a][i],1-col);
		}	
	}
}

int a,b;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i =0;i<n-1;i++)
{
	scanf("%d%d",&a,&b);
	graph[a].push_back(b);
	graph[b].push_back(a);
}	
//printf("here\n");
for(int i = 1;i<=n;i++)
{
cin>>ch;
color[i]=(ch=='B');
}
long long ans = 0;
cnt=0;
for(int i = 1;i<=n;i++)
{
if(!visited[i])
{
cnt=0;
dfs(i,color[i]);
ans = (ans+sum(cnt)%MOD)%MOD;
}
}
cout<<ans<<endl;

	return 0;
}
