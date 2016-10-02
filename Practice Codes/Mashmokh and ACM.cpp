#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007 
int n,k;

ll dp[2003][2003];
ll compute(int pos,int b)
{
	if(pos==k)
	return 1;
	
	if(dp[pos][b]!=-1)
	return dp[pos][b];
	ll ans = 0;
	int num = b,j=1;
	while(num<=n)
	{
		ans = (ans + compute(pos+1,num))%MOD;
		j++;
		num = b*j;	
	}
	return dp[pos][b] = ans;
	
}

int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&k);
	cout<<compute(0,1);
	return 0;
}
