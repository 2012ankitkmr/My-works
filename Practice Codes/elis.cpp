#include<stdio.h>
#include<string.h>
int a[25];
int dp[25];
int lis(int n)
{
	int i,j,max=0;
for(i=0;i<n;i++)
dp[i]=1;
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j]&&dp[i]<dp[j]+1)
			dp[i]=dp[j]+1;	
		}
	}
	
	for(i=0;i<n;i++)
	if(max<dp[i])
	max=dp[i];
	
	return max;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("%d",lis(n));
	return 0;
}
