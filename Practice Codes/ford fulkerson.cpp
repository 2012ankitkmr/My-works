#include<bits/stdc++.h>
using namespace std;
int matrix[100][100];
int gmatrix[100][100];
long int v,e;
void readedges()
{
	int i,x,y,z;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		matrix[x][y]=z;
	}
	
}

bool bfs(int s,int t,int parent[])
{
	bool visited[v];
	memset(visited,0,sizeof visited);
	visited[s]=1;
	queue<int>q;
	q.push(s);
	 parent[s] = -1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<v;i++)
		{
			if(!visited[i]&&gmatrix[p][i])
			{
				visited[i]=1;
				q.push(i);
				parent[i]=p;
			}
			
		}
		
	}
	return visited[t]==true;
}
int fordfulkerson(int s,int t)
{
	for(int i=0;i<v;i++)for(int j=0;j<v;j++)gmatrix[i][j]=matrix[i][j];
	int parent[v+1];
	int i,j;
	int max_flow=0,flow=INT_MAX;
	
	while(bfs(s,t,parent))
	{
		
		for(i=t;i!=s;i=parent[i])
		{
				j=parent[i];
		//printf("j=%d,i=%d\n",j,i);
		flow=min(flow,gmatrix[j][i]);
		}
		for(i=t;i!=s;i=parent[i])
		{
			j=parent[i];
		gmatrix[j][i]-=flow;
		gmatrix[i][j]+=flow;
		}
		max_flow+=flow;
	}	
	return max_flow;
}
int main()
{	
scanf("%ld%ld",&v,&e);	
readedges();
int ans= fordfulkerson(0,6);
printf("%ld\n",ans);
	return 0;
}
