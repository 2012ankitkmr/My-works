#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

vector<pair<int,int> > g[50004];
int a[50004] , n , m ;
ll c[50004] , ans ;

bool has[50004];

void dfs( int u , int prev )
{
	if( has[u] )
	c[u] = 1;
	else
	c[u] = 0;
	int node , cost;
	for(int i = 0 ; i < g[u].size() ; i++)
	{
		node = g[u][i].fi;
		cost = g[u][i].se;
		
		if( node != prev)
		{
		dfs( node , u );
		c[u] = c[u] + c[node];
		ans = ans + 2 * (ll)cost * ( c[node] * ( (ll)m - c[node] ) );
	   }
	}

}


ll gcd(ll a , ll b) {
  while (b) {
    a %= b;
    swap(a , b);
  }
  return a;
}

int main()
{
//	freopen("in.txt","r+",stdin);
	
	ll num,den;
	int t , u , v , l;
	
	cin>>t;

	while(t--)
	{
	scanf("%d%d", &n , &m );
	for(int i = 0 ; i < n - 1 ; i++ )
	{
	
	scanf("%d%d%d" , &u , &v , &l );	
	g[u].pb( mp ( v , l ) );
	g[v].pb( mp ( u , l ) );
	
	}
	for(int i = 0 ; i < m ; i++ )
	{
	scanf("%d", &a[i] );
    has[a[i]] = 1;
	}
	ans = 0;
	
	dfs( 1 , -1 );
	
	for(int i = 1 ; i <= n ; i++)
	g[i].clear();
	
//	printf("\nans = %d\n", ans );
	
	num = ans;
	den = (ll)m * (ll)m;
	ans = gcd( num , den );
	num /= ans;
	den /= ans;

    printf("%lld %lld\n", num , den );

//	for(int i = 0 ; i < m ; i++ )
//	has[a[i]] = 0;
    memset( has , 0 , sizeof has );	
    memset( c , 0 , sizeof c );

	}
	return 0;
}
