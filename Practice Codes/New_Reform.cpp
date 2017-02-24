#include "bits/stdc++.h"
using namespace std;
#define pb push_back

int a,b,n,m,ans;
vector<int>g[100005];
bool vis[100005];

void dfs(int u,int prev)
{
  vis[u]=1;
  for(int i = 0;i<g[u].size();i++)
  {
    if(g[u][i]==prev)
    continue;
    if(!vis[g[u][i]])
    dfs(g[u][i],u);
    else
    a=0;
  }
}


int main()
{
  ans =0;
  scanf("%d%d",&n,&m);
  for(int i = 0;i<m;i++)
  {
  scanf("%d%d",&a,&b);
g[a].pb(b);
g[b].pb(a);
  }
  for(int i = 1;i<=n;i++)
  {
    if(!vis[i])
    { a=1;
      dfs(i,0);
      ans+=a;
    }
  }
cout<<ans<<endl;
  return 0;
}
