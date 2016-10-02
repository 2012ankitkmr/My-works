#include<bits/stdc++.h>
int a[5000];
int maxcsum(int n)
{
	int i,maxsum=0,dp[n];
	if(a[0]>0)
	dp[0]=a[0];
	else
	dp[0]=0;
	for(i=1;i<n;i++)
	{
		if(dp[i-1]+a[i]>0)
          dp[i]=dp[i-1]+a[i];		
		else
		dp[i]=0;
	}
	for(i=0;i<n;i++)
 if(maxsum<dp[i])
 maxsum=dp[i];
 return maxsum;
}


int main()
{

int n,t,i;
for(scanf("%d",&t);t--;)
{
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);	
}	
printf("maxsum=%d\n",maxcsum(n));	
}
return 0;	
}
