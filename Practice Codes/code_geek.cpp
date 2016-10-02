#include <iostream>
using namespace std;
#define mod 1000000007
#define C 1001
long long int lower[C]={0},upper[C]={0};
long long int dp[C][C];
int n,m,c,x;
void input()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0;i<=c;i++)
	{lower[i] =0; upper[i] = 0;}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		upper[x]++;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		lower[x]++;
	}
	for(int i=0;i<=c;i++)
	lower[i] *= upper[i];
	for(int i=1;i<=c;i++)
	lower[i] += lower[i-1];
}
void output()
{
	for(int i=1;i<=c;i++)
	{
		printf("%d ",dp[c][i]);
	}
}
int main() {
	input();
	for(int i=0;i<=c;i++)
	{
		dp[0][i] = 0;
		dp[i][0] = lower[i] % mod;
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=c;j++)
		{
			dp[i][j] = ((lower[i]-lower[i-1])*dp[i-1][j-1])%mod + dp[i-1][j];
			dp[i][j] %= mod;
		}
	}/*
	for(int i=0;i<=c;i++)
	{
		for(int j=0;j<=c;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	output();
}
