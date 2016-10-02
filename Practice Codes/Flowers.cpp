#include<bits/stdc++.h>
using namespace std;

#define  ll long long unsigned
#define MOD 1000000007

ll dp[100005],n,k,sumdp[100005],f,l,r;


int main()
{
cin>>n>>k;	
	dp[0]=1;
	for(ll i = 1 ; i<= 100000 ; i++ )
	{
		if(i<k)
		dp[i]=1;
		else
		dp[i] = (dp[i-1]+dp[i-k] )%MOD;
	}
	
	sumdp[0] = 0;
	for(ll i = 1 ;i <=100000 ; i++ )
	{
		sumdp[i] = (sumdp[i-1]+dp[i])%MOD;
	}

	
	for(int i = 0; i < n ; i++ )
	{
cin>>l>>r;
cout<<(sumdp[r]-sumdp[l-1]+MOD)%MOD<<endl;
	}
	
	return 0;
}
