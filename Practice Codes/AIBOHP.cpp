#include<stdio.h>
#include<string.h>
char string1[6150],string2[6150];
long int dp[6150][6150];
long int max(long int a,long int b)
{
	return a>b?a:b;
	}
long int lowestcommonsubsequence(long int a, long int b)
{

long int i,j;
for(i=0;i<=a;i++)
{
	for(j=0;j<=b;j++)
	{
		if(j==0||i==0)
		dp[i][j]=0;
		else if(string1[i-1]==string2[j-1])
		dp[i][j]=1+dp[i-1][j-1];
	else
	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
}
return dp[a][b];
}

int main()
{
	long int len,t,i;
	for(scanf("%ld",&t);t--;)
	{
		scanf("%s",string1);
		len=strlen(string1);
		for(i=0;i<len;i++)
		string2[i]=string1[len-i-1];
	
		printf("%ld\n",len-lcs(len,len));
		
	}
	return 0;
}
