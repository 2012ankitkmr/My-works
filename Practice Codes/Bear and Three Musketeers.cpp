#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>mus[4003];
int adj[4003][4003];

int main()
{
//	freopen("in.txt","r+",stdin);
	int n,m,sum,a,b,minval =INT_MAX;
	scanf("%d%d",&n,&m);
	
	for(int i =0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		mus[a].pb(b);
		mus[b].pb(a);
		adj[a][b]=1;
		adj[b][a]=1;
	}
	
	for(int i = 1 ;i <= n ; i++)
	{
		for(int j = 0 ; j < mus[i].size();j++)
		{
		
			for(int k = j+1 ; k<mus[i].size();k++)
			{
				if(adj[mus[i][j]][mus[i][k]]==1)
				{
				sum = 0;
				sum = mus[i].size()+mus[mus[i][j]].size()+mus[mus[i][k]].size();
				
			//	printf("%d %d %d\n",mus[i].size(),mus[mus[i][j]].size(),mus[mus[i][k]].size());
			//	printf("sum = %d\n",sum);
				sum-= 6;
				minval = min(minval,sum);
            	}
			}
			
		}
	//	printf("\n");
	}
	if(minval!=INT_MAX)
	cout<<minval<<endl;
	else
	cout<<"-1"<<endl;
	return 0;
}
