#include<bits/stdc++.h>
using namespace std;


struct box{
	int a,b,c;	
}bo[152];
	int n;
bool comp(box x,box y)
{
	int area1 = x.b*x.c,area2 = y.b*y.c;
	return area1>=area2;
}
int dp[152];
int compute(int pos,int sum)
{
	if(pos==n)
	return sum;
	
	if(dp[pos]!=-1)
	return dp[pos];
	
	int ans = INT_MIN;
	for(int i = pos+1;i<=n;i++)
	{
		if(bo[pos].b>bo[i].b&&bo[pos].c>bo[i].c)
		{
			ans=max(ans,compute(i,sum+bo[i].a));
		}
	}
	return  dp[pos]=ans;
}


int main()
{

memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	n=n*3;
	for(int i =1;i<=n;)
	{
		printf("%d%d%d",&x,&y,&z);
		bo[i].a = x;
		bo[i].b = y;
		bo[i].c = z;
		i++;
		bo[i].a = y;
		bo[i].b = x;
		bo[i].c = z;
		i++;
		bo[i].a = z;
		bo[i].b = x;
		bo[i].c = y;
		i++;
	}
	bo[0].a = INT_MAX;
	bo[0].b = INT_MAX;
	bo[0].c = INT_MAX;
	sort(a+1,a+n+1,comp);
	
	cout<<compute(0,0);
	
	return 0;
}
