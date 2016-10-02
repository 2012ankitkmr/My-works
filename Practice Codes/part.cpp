#include<stdio.h>
#include<string.h>
long int fee[102],fun[102];
long int dp[505][505],totalfee;
long int max(long int a,long int b)
{
	return a>b?a:b;
}

long int knapsack(long int budget,long int n)
{
memset(dp,0,sizeof(dp));
	int i,j,flag;
for(i=1;i<=n;i++)
{
for(j=1;j<=budget;j++)
{
	if(i==1)
	{
		if(j>=fee[i-1])
		{
		dp[i][j]=fun[i-1];
	}
	else
	dp[i][j]=0;
}
	else{
		if(j<fee[i-1])
	       {
	       dp[i][j]=dp[i-1][j];
	     

}
	    else
		  {
		   dp[i][j]=max(fun[i-1]+dp[i-1][j-fee[i-1]],dp[i-1][j]);
}
	}	
}	
}
return dp[n][budget];	
}
long int totalfee(long int n)
{
	
	
}

int main()
{
	long int total,n,i;
	scanf("%ld%ld",&total,&n);
	for(i=0;i<n;i++)
	{
	scanf("%ld%ld",&fee[i],&fun[i]);	
	}
	
	printf("%ld %ld\n",totalfee(n),knapsack(total,n));
	return 0;
}
