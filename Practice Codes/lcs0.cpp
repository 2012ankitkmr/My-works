#include<stdio.h>
#include<string.h>
char x[50005],y[50005];
long int dp[50000][50000];

long int max(long int a,long int b)
{
	return a>b?a:b;
}
long int lcs(long int m,long int n)
{
	if(m==0||n==0)
	return 0;
	if(dp[m][n]!=-1)
	return dp[m][n];
	if(x[m-1]==y[n-1])
	return dp[m][n]=1+lcs(m-1,n-1);
	else
	return dp[m][n]=max(lcs(m,n-1),lcs(m-1,n));
}

int main()
{
	long int a,b;
scanf("%s",x);
scanf("%s",y);
a=strlen(x);
b=strlen(y);
memset(dp,-1,sizeof dp);
printf("%ld",lcs(a,b));

	return 0;
	
}
