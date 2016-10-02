#include<bits/stdc++.h>
using namespace std;


int adj[1003][1003],In[1003],out[1003],diff[1003],n,ans,sum;

int main()
{
	
	freopen("in.txt","r+",stdin);
	int k = 0;
	while(1)
	{ 
	    k++;
		scanf("%d",&n);
		//printf("here\n");
		if(n==0)
		break;
		memset(In,0,sizeof In);
		memset(out,0,sizeof out);
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			scanf("%d",&adj[i][j]);
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				In[j]+=adj[i][j];
				out[i]+=adj[i][j];
			}
		
		}
		
		sum = 0;
		for(int i = 0;i<n;i++)
		{
		//	printf("%d %d\n",In[i],out[i]);
			sum+=In[i];
		diff[i]=In[i]-out[i];
	}
		ans  =0;
		for(int i = 0;i<n;i++)
		if(diff[i]>=0)
		ans+=diff[i];
	
		printf("%d. %d %d\n",k,sum,ans);
	}
	
	
	return  0;
}
