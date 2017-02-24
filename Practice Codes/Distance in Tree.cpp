#include<bits/stdc++.h>
using namespace std;
#define ll long long
 #define ge(i,a,b) for(int i=a;(i)<=(int)(b);++(i))

vector<int>g[50004];
ll ans = 0;
int d[50004][501],k,par[50004];
void dfs(int v){
	d[v][0] = 1;
	for (int x : g[v]){
		if (x == par[v]) continue;
		par[x] = v;
		dfs(x);
		ge(i, 0, k-1) ans += d[x][i]*1LL*d[v][k-i-1];
		ge(i, 1, 500) d[v][i] += d[x][i-1];
	}
}
int main()
{
	int n;
	cin >> n >> k;
	ge(i, 0, n - 2){
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y); g[y].push_back(x);
	}
	dfs(0);
	cout << ans;
}
