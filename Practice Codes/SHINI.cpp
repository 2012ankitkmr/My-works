#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[10004][11];

int n,k;
ll compute(int pos,int consec)
{
	if(pos==n)
	return 1;	
	
	if(dp[pos][consec]!=-1)
	return dp[pos][consec];
	ll count =0;
	if(consec<k-1)
	count = (count +compute(pos+1,consec+1))%MOD;
	count = (count +compute(pos+1,0))%MOD;
	return dp[pos][consec] =count;
}


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",compute(1,0));
		
	}
	
	
	return  0;
}
