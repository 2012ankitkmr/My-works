#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define INF 1e9
int spl[MAXN],arr[MAXN];

vector<int> graph[MAXN] , weight[MAXN];

struct gnode{
	int x , y;
	bool operator<(const gnode&sec)const{
		return y > sec.y;
	}
	
	gnode(){}
	gnode(int node,int w)
	{
		x = node;
		y = w;
	}
};

int n , m , k , temp , a , b , z , dis[MAXN];

int solve()
{
	int ret = INF , v, u , cost ;
	
	for(int i = 0; i < k ; i++)
	{
		 u = arr[i];
	priority_queue < gnode > q;
	q.push( gnode ( u , 0 ) );
	
	for(int j = 0 ; j <= MAXN ; j++ ) 
	dis[j] = INF;
	
	dis[u] = 0;
//	printf("Entering with %d\n",u);
	while(!q.empty())
	{
		gnode p = q.top();
		q.pop();
	//	printf("Dequeing %d\n",p.x);
		if( p.y > ret)  // Step to find minimum
		break;
		if( spl[p.x] && p.x != u )
		{
			//printf("Returning %d %d\n",p.x,p.y);
			ret = p.y;
			break;
		}
		
		
		for(int j = 0; j < graph[p.x].size() ; j++ )
		{
			v = graph[p.x][j];
			cost = weight[p.x][j];
		//	printf("Crawling %d\n",v);
			if( dis[v] > dis[p.x] + cost)
			{ dis[v] = dis[p.x] + cost;
			q.push(gnode( v , dis[v] ));
			}			
		}
		
	}
	
}
return ret;
}


int main()
{
//	freopen("in.txt","r",stdin);

	scanf("%d %d %d", &n , &m , &k );

	for(int i = 0 ;i < k ; i++ ) 
	{
		scanf("%d", &arr[i] );
		spl[arr[i]] = 1;
	}

	for(int i = 0 ;i < m ; i++ )
	{
	scanf("%d %d %d", &a , &b , &z);
	graph[a].push_back(b);
	graph[b].push_back(a);
	weight[a].push_back(z);
	weight[b].push_back(z);
	}

	int ans = solve();
	printf("%d\n", ans);

	return 0;
}
