#include<bits/stdc++.h>
using namespace std;

int n,m,d;

int a[10004];

int dp[100004];


int main()
{
	
//	freopen("in.txt","r+",stdin);
	scanf("%d%d%d",&n,&m,&d);
	
	n = n*m;
	for(int i = 0 ; i < n ; i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	//a[n]= INT_MAX;
	
	
	for(int i =1;i<n;i++)
	dp[0] +=(a[i]-a[0]);
	
	int ans = dp[0],diff;
int	pivot = 0;
	for(int i = 1;i<n;i++)
	{
		diff = a[i]-a[i-1];
		dp[i]=dp[i-1] - (n-i)*(diff) + i*(diff);
if(ans>dp[i])
{
	ans=dp[i];
	pivot = i;
}		
	} 
		for(int i = 0 ; i < n ; i++)
	{
		if(abs(a[i]-a[pivot])%d!=0)
		{
//			printf("at %d",a[i]);
			printf("-1\n");
			return 0;
		}
	}

	cout<<ans/d;
	
	 
	return 0;
}
