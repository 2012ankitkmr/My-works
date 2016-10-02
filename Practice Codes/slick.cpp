#include<bits/stdc++.h>
#include<queue>
using namespace std;

bool slick[252][252];
bool visited[252][252];
long int ans[32502];
long int process[32502];
void dfs(int i,int j,int n,int m,int splick_no)
{
	if(slick[i][j])
	{
		ans[splick_no]++;
	visited[i][j]=1;
if(i>1&&!(visited[i-1][j])) dfs(i-1,j,n,m,splick_no);
		if(i<n&&!(visited[i+1][j])) dfs(i+1,j,n,m,splick_no);
		if(j>1&&!(visited[i][j-1])) dfs(i,j-1,n,m,splick_no);
		if(j<m&&!(visited[i][j+1])) dfs(i,j+1,n,m,splick_no);

}
}

int main()
{
	long int n,m,i,j,s;
	while(1)
	{
		
		scanf("%ld%ld",&n,&m);
		if(n==0&&m==0)
		break;
		
     	memset(visited,0,sizeof(visited));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			scanf("%d",&slick[i][j]);
		}
		s=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(!visited[i][j]&&slick[i][j])
				{
					dfs(i,j,n,m,s++);
				
				}
			}
		}
		printf("%ld\n",s-1);
		memset(process,0,sizeof(process));
		for(i=1;i<=32500;i++)
		{
			process[ans[i]]++;
		}
			for(i=1;i<=32500;i++){
			
			if(process[i]!=0){
				printf("%ld %ld\n",i,process[i]);
			}
		}
	}
	
	return 0;
}
