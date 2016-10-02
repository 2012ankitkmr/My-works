#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long dp[100005];

int main()
{
	int test,n;
	long long ans;
for(scanf("%d",&test);test--;)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	dp[0]=a[0];
	dp[1]=max(a[0],a[1]);
	for(int i=2;i<n;i++)
	dp[i]=max(dp[i-1],dp[i-2]+a[i]);
	
printf("%lld\n",dp[n-1]);
	
}
	
	return  0;
}
