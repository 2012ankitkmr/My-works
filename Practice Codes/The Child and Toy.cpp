#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,y;
	long long ans=0;
	
	int v[100005];
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
	{
	scanf("%d",&v[i]);
}

for(int i=0;i<m;i++)
{
	scanf("%d%d",&x,&y);
	ans+=min(v[x-1],v[y-1]);
}
cout<<ans<<"\n";
	return 0;
}
