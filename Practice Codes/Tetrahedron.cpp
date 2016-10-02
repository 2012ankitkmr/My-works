#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int n ;

ll dp[10000007];
int main()
{
	dp[1]=0,dp[2]=3;
	for(int i = 3 ; i<=10000000 ; i++)
	dp[i] = (( 3 * dp[i - 2] ) % MOD + ( 2 * dp[i - 1] ) %MOD ) %MOD;
	
	scanf("%d",&n);
	cout<<dp[n];
	
	
	return  0;
}
