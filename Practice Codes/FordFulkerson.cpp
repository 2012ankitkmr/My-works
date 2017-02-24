#include<bits/stdc++.h>
using namespace std;
#define N 6

bool bfs(int src,int tar,int grp[N][N],int parent[])
{
queue<int>q;
q.push(src);
bool vis[N];
for(int i =0 ;i<N;i++)
vis[i] = 0;
vis[src] = 1;
parent[src] = -1;
while(!q.empty())
{
int p = q.empty();
q.pop();
for(int i = 0 ; i < N ; i++ )
{
	if( grp[p][i] > 0 && (!vis[i] ))
	{
		
		printf("here %d \n",i);
		parent[i] = p;
		q.push(i);
		vis[i] = 1;
	}
}	
	
}	
	
return (vis[tar]==1);
}


int fordfulkerson(int gr[N][N],int s,int t)
{
	int resGr[N][N];
	int parent[N],u;
	
	for(int i = 0;i<N;i++){
	for(int j = 0;j<N;j++)
	{
//	printf("%d ",gr[i][j]);
	resGr[i][j] = gr[i][j];
}
//printf("\n");
}

int max_flow = 0 , min_flow;	
//	printf("%d\n",min_flow);	
while(bfs(s,t,resGr,parent))
{
	min_flow = INT_MAX;
	for(int v = t; v !=s ; v = parent[v])
	{
		u = parent[v];
		min_flow = min(min_flow,resGr[u][v]);
	}
	
	for(int v = t ; v != s ; v = parent[v])
	{
		u = parent[v];
		resGr[u][v] -= min_flow;
		resGr[v][u] += min_flow;
	}
	max_flow+=min_flow;

}
	return max_flow;
}



int main()
{
	
	int gr[N][N] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
	
	
	int ans = fordfulkerson(gr,0,5);
	printf("%d\n",ans);	
	
	return 0;
}
