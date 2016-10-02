#include<bits/stdc++.h>
using namespace std;
int a[5000];
int max(int a,int b)
{
	return a>b?a:b;	
}
int max3(int n)
{
	int i,m,dp[n+1];	
dp[0]=a[0];
dp[1]=a[0]+a[1];
m=max(a[0]+a[1],a[1]+a[2]);
dp[2]=(m,a[0]+a[2]);
for(i=3;i<n;i++)
{
	m=max(a[i]+a[i-1]+dp[i-3],a[i]+dp[i-2]);
	dp[i]=max(m,dp[i-1]);
}
return dp[n-1];
}

int main()
{
	int n,t,i;
	
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
printf("maxsum=%d\n",max3(n));		
	}
	
	return 0;
}
