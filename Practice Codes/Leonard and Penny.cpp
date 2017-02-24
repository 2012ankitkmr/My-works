#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int a[16];
ll dp[16][1<<16];
	int n;

ll compute(int pos,int bitmask)
{
	//printf("here\n");
	if(__builtin_popcount(bitmask)==n)
	{
		return 0;
	}
	//system("pause");
	if(dp[pos][bitmask]!=-1)
	return dp[pos][bitmask];
	
	ll ans = INT_MIN,p;
	for(int i = 1;i<=n;i++)
	{
		if(((1<<i)&(bitmask))==0)
		{
	//		printf("%d\n",i);
		    p = __gcd(a[pos],a[i]);
		    if(pos==0)
    		  p = 0;
			ans = max(ans,p+compute(i,bitmask|(1<<i)));
		}
	}
	return dp[pos][bitmask]=ans;
	
}

int main()
{
	scanf("%d",&n);
	for(int i  = 1;i<=n;i++)
	scanf("%d",&a[i]);
	memset(dp,-1,sizeof dp);
cout<<compute(0,0);	
	
	return 0;
}
