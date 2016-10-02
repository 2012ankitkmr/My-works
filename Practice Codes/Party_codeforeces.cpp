#include<bits/stdc++.h>
using namespace std;


vector<int>graph[2003];

int dfs(int a,int cnt)
{
int ans = cnt;
	for(int i = 0;i<graph[a].size();i++)
	{
	ans = max(ans,dfs(graph[a][i],cnt+1));	
	}
	return ans;
}

int main()
{
	int n,temp,ans =1 ;
	
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		cin>>temp;
		if(temp!=-1)
		graph[i].push_back(temp);
	}
	
	for(int i = 1;i<=n;i++ )
	{
		ans = max(ans,dfs(i,1));
	}
printf("%d\n",ans);
 
 
	return 0;
}
