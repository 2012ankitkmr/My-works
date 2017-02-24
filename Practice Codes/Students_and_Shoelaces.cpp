#include "bits/stdc++.h"
using namespace std;

int size[102];
int adj[102][102];
int main()
{
int n,m,a,b;
scanf("%d%d",&n,&m);
memset(size,0,sizeof size);
for(int i = 0;i<m;i++)
{
  scanf("%d%d",&a,&b);
  adj[a][b]=1;
  adj[b][a]=1;
  size[a]++;
  size[b]++;
}
int ans=0,fl=0;
while(1)
{
  vector<pair<int,int> >pairs;
for(int i = 1;i<=n;i++)
{

if(size[i]==1)
{
  fl=1;
  int p;
  for(int j = 1;j<=n;j++)
  {
    if(adj[i][j]==1)
    {
      p=j;
      break;
    }
  }
  pairs.push_back(make_pair(i,p));
}

}
for(int j = 0;j<pairs.size();j++)
{
  size[pairs[j].first]--;
  size[pairs[j].second]--;
  adj[pairs[j].first][pairs[j].second] = 0;
  adj[pairs[j].second][pairs[j].first] = 0;
}

if(!fl)
break;
ans++;
fl=0;
}

printf("%d\n",ans);
  return 0;
}
