#include<bits/stdc++.h>
using namespace std;


int n,w[200005],h[200005];

long long dp[200005];
int main()
{
	scanf("%d",&n);
	int add = 0,maxin=-1,maxh=-1;
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d",&w[i],&h[i]);
		add+=w[i];
		if(maxh<h[i])
		{
			maxh = h[i];
			maxin = i;
		}
	}
	
	int sec_maxin;
	maxh = -1;
	for(int i =0;i<n;i++)
	{
		if(maxh<=h[i])
		{
			if(i!=maxin)
			{
				sec_maxin = i;
				maxh = h[i];
			}		
		}
	}

add-=w[0];
	dp[0]=(add)*(h[0==maxin?sec_maxin:maxin]); 


	for(int i =1;i<n;i++)
	{
		add+=w[i-1];
		add-=w[i];
	dp[i]=(add)*(h[i==maxin?sec_maxin:maxin]); 
		
	}
	
	for(int i = 0;i<n;i++)
	cout<<dp[i]<<" ";
	return  0;
}
