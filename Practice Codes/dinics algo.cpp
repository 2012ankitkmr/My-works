#include <bits/stdc++.h>
using namespace std;

const int maxnodes = 5005;

int nodes = maxnodes, src, des;
int dis[maxnodes], work[maxnodes];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, cap};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
 memset(dis,-1,sizeof dis);
 
 dis[src] = 0;
 queue<int>q;
 q.push(src);
  while (!q.empty()) {
    int p=q.front();
    q.pop();
    for (int j = 0; j < g[p].size(); j++) {
      Edge &e = g[p][j];
      int v = e.to;
      if (dis[v] < 0 && e.f < e.cap) {
        dis[v] = dis[p] + 1;
        q.push(v);
      }
    }
  }
  return dis[des]>= 0;
}

int dinics_dfs(int u,int f)
{
	if(u==des)
	return f;
	for(int &i=work[u];i<(int)g[u].size();i++)
	{
		Edge &e=g[u][i];
		if(e.cap<=e.f)
		continue;
		int v=e.to;
		if(dis[v]==dis[u]+1)
		{
			int df=dinics_dfs(v,min(f,e.cap-e.f));
			if(df>0)
			{
				e.f+=df;
				g[v][e.rev].f-=df;
				return df;
			}			
		}
	}
	return 0;
}

int maxflow(int _src, int _des) {
  src = _src;
  des = _des;
  int result = 0;
  while (dinic_bfs()) {
memset(work,0,sizeof work);
while(int delta=dinics_dfs(src,INT_MAX))
result+=delta;
}
return result;
}

int main()
{
	freopen("in.txt","r",stdin);
int n,e,a,b,c;	
	scanf("%d%d",&n,&e);
	
	for(int i=0;i<e;i++)
	{
	scanf("%d%d%d",&a,&b,&c);	
	addEdge(a,b,c);	
	}
	cout<<maxflow(0,4)-1<<"\n";
    return 0;
}
