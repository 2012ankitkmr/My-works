#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[1000]; 
ll compute(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 1;
if(dp[n]!=-1)
return dp[n];
	ll ret=compute(n-1)*compute(n-1)+compute(n-2);
	return dp[n]=ret;
}

int main()
{
	ll n=55;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	printf("%lld ",compute(i));
	
	return 0;
}
