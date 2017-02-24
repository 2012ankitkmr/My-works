#include<bits/stdc++.h>
using namespace std;

	int n;

int a[302];
char s[302][302];
bool vis[302];
priority_queue<int,vector<int>, greater<int> > lis[302];
 
int num[302];

void dfs(int u,int nlis)
{
	lis[nlis].push(a[u]);
	num[a[u]]=nlis;
			vis[u]=1;
	for(int i = 0;i<n;i++)
	{
		if(!vis[i]&&s[u][i]=='1')
		{
	
			dfs(i,nlis);
		}
	}
	
}

int main()
{
	//freopen("in.txt","r+",stdin);
	scanf("%d",&n);
	for(int i =0 ;i<n;i++)
	scanf("%d",&a[i]);
	getchar();
	for(int i = 0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	int nl=0;
	for(int i =0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs(i,nl);
			nl++;
		}
	}
	int ans[302];
	for(int i =0;i<n;i++)
	{
		ans[i] = lis[num[a[i]]].top();
		lis[num[a[i]]].pop();
		printf("%d ",ans[i]);
	}
	printf("\n");
	
	return 0;
}
