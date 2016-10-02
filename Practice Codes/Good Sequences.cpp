#include<bits/stdc++.h>
using namespace std;

#define ll long long 


vector<ll>fact[100005];

ll dp[100005],d[100005];

ll a[100004];
int main()
{
	
	ll n,p,num;
	scanf("%I64d",&n);
	
	for(int i = 0;i<n;i++)
	scanf("%I64d",&a[i]);
	
	fact[1].push_back(1);
	for(int i = 2;i<=100000;i++)
	{
	
	if(fact[i].size()>0)
	continue;	
		 p =1,num;
		while((num=i*p)<=100000)
		{
			fact[num].push_back(i);			
			p++;
		}
	}
	ll maxval,ans=0;
for(int i  = 0;i<n;i++)
{
	maxval = 0;
	for(int j = 0;j<fact[a[i]].size();j++)
	{
		maxval = max(maxval,d[fact[a[i]][j]]);
	}
	
	maxval++;
	dp[a[i]]= maxval;
	
	for(int j = 0;j<fact[a[i]].size();j++)
	{
	d[fact[a[i]][j]]=maxval;
	}
	ans = max(ans,dp[a[i]]);
}
	
	cout<<ans<<endl;
	
	return 0;
}
