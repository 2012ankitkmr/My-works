#include<bits/stdc++.h>
using namespace std;

int a[100005],n,rcost[100005],scost[100005];


void bfs_raj(int x)
{
	queue<int>q;
	q.push(x);
	bool vis[100005];
		memset(vis,0,sizeof vis);

	vis[x]=1;
	for(int i =0;i<100003;i++)
	rcost[i]= INT_MAX;
	rcost[x]=0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(p+1<n)
		{		
		if(!vis[p+1])
		{
			vis[p+1]=1;
			q.push(p+1);
			
		}
		rcost[p+1]= min(rcost[p+1],1+rcost[p]);
     	}
		
		if(p+a[p]<n)
		{		
		if(!vis[p+a[p]])
		{
			vis[p+a[p]]=1;
			q.push(p+a[p]);
			
		}
		rcost[p+a[p]]= min(rcost[p+a[p]],1+rcost[p]);
     	}
	}
	
}

void bfs_sim(int x)
{
	queue<int>q;
	q.push(x);
	bool vis[100005];
	memset(vis,0,sizeof vis);
	vis[x]=1;
	for(int i = 0 ; i < 100003 ; i++)
	scost[i] = INT_MAX;
	scost[x] = 0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if((p-1) >=0)
		{		
		if(!vis[p-1])
		{
			vis[p-1]=1;
			q.push(p-1);
			
		}
		scost[p-1]= min(scost[p-1],1+scost[p]);
     	}
		
		if(p-a[p]>=0)
		{		
		if(!vis[p-a[p]])
		{
			vis[p-a[p]]=1;
			q.push(p-a[p]);
			
		}
		scost[p-a[p]]= min(scost[p-a[p]],1+scost[p]);
     	}
	}
	
}
int main()
{
	
	int t,ans;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
		
		bfs_raj(0);
		bfs_sim(n-1);
		
		ans = INT_MAX;
			
		for(int i = 0;i<n;i++)
		{
			ans = min(ans,max(rcost[i],scost[i]));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
