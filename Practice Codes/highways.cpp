#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
#define INF 10000000

long int dis[100005];
//long int que[100005]; 
struct li
{
	long int v;
	long int weight;
};
bool operator <( li a, li b ) {
	return a.weight < b.weight;
}

void dijkstra(vector<li>graph[],long int V,long int src,long int des)
{
	long int temp,i;
	li start,new1;
	for(i=1;i<=V;i++)
	dis[i]=INF;
	dis[src]=0;
priority_queue< li > q;
	q.push( ( li ) { src, 0 } );
	while ( !q.empty() ) {
		li p = q.top();
		q.pop();

		for ( i = 0; i < graph[ p.v ].size(); ++i ) {
			li k = graph[ p.v ][ i ];
			if ( dis[ p.v ] + k.weight < dis[ k.v ] ) {
				dis[ k.v ] = dis[ p.v ] + k.weight;
				q.push( k );
			}
		}
	}
		if(dis[des]!=INF)
	printf("%ld\n",dis[des]);
	else
	printf("NONE\n");
}

int main()
{
	int t;
	long int i,n,m,src,des,a,b,w;
	for(scanf("%d",&t);t--;)
	{
		scanf("%ld%ld%ld%ld",&n,&m,&src,&des);
		vector<li>graph[n+1];
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&w);
			graph[a].push_back((li){b,w});
			graph[b].push_back((li){a,w});
		}
		dijkstra(graph,n,src,des);
		
	}
	
	return 0;
}
