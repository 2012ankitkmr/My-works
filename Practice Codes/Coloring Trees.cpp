#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[102][102][102];
int a[102],p[102][102];
int n,m,k;

ll compute(int pos,int sets,int prev)
{
	if(sets>k)
	return 9999999999999;
	
	if(pos==n)
	{
		if(sets==k)
		return 0;
		else 
		return 9999999999999;
		
	}
	
	if(a[pos])
	{
	if(a[pos]==prev)
	return compute(pos+1,sets,prev);
	else
	return compute(pos+1,sets+1,a[pos]);
    }
    
    if(dp[pos][sets][prev]!=-1)
    return dp[pos][sets][prev];
    
    ll minval = 9999999999999;
    for(int i = 1;i<=m;i++)
    {
    	if(i==prev)
        minval = min(minval,p[pos][i]+compute(pos+1,sets,prev));	
    	else
    	minval = min(minval,p[pos][i]+compute(pos+1,sets+1,i));	
    }
    return dp[pos][sets][prev] = minval;
}


int main()
{
	
	memset(dp,-1,sizeof dp);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(int i =0;i<n;i++)
	{
		for(int j =1;j<=m;j++)
		scanf("%d",&p[i][j]);
	}
	
	ll ans =compute(0,0,0);
	if(ans==9999999999999)
	ans = -1;
	cout<<ans;
	
	return 0;
}
