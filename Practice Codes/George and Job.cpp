#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int a[5005];
int n,m,k;
ll max(ll a,ll b)
{
	return a>b?a:b;
}

ll prefix_sum[5005];
ll sum(int i,int j)
{
	if(i<0)
	return 0;
	if(i==0)
	return prefix_sum[j];
	else
	return prefix_sum[j]-prefix_sum[i-1];
	
}
ll dp[5005][5005];
ll compute(int pos,int sets)
{


if(sets==0)
return 0;


if(pos<0)
return INT_MIN;


    if(dp[pos][sets]!=-1)
    return dp[pos][sets];	
	
	ll ans = 0;

//cout<<sum(pos-m+1,pos)<<endl;
ans = max(sum(pos-m+1,pos)+compute(pos-m,sets-1),compute(pos-1,sets));

return dp[pos][sets]= ans;
	
}


int main()
{
	
	scanf("%d%d%d",&n,&m,&k);

	memset(dp,-1,sizeof dp);
	
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	prefix_sum[0] = a[0];
	for(int i = 1 ;i < n;i++)
	{
		prefix_sum[i] = prefix_sum[i-1] + a[i];
	}
cout<<compute(n-1,k)<<endl;	
	return  0;
}
