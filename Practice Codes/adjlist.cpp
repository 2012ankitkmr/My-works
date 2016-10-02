#include<bits/stdc++.h>
using namespace std;
#define max 1000
bool visited[max];
class graph
{
	int v;
	list<int>*adj;
	public:
		graph(int v);
		void addedges(int v,int w);
		void bfs(int s);
};
graph::graph(int v)
{
	adj=new list<int>[v];
}
void graph::addedges(int v,int w)
{
	adj[v].push_back(w);
}

void graph::bfs(int s)
{
	memset(visited,0,sizeof visited);
	queue<int>q;
	visited[s]=1;
	q.push(s);
list<int>::iterator i;
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=1;
				q.push(*i);
			}
		}
	}
	
}
int main()
{
graph g(8);
printf("here\n");
g.addedges(1,2);

g.addedges(2,3);	
g.addedges(2,4);
g.addedges(4,5);
g.addedges(5,6);
g.addedges(5,7);
	g.bfs(1);
	return 0;
}
