#include<stdio.h>
#include<string.h>
char s1[10],s2[10];
int dp[10][10];
int max(int a,int b)
{
	return a>b?a:b;
}
int lcs(int a,int b)
{
	if(a==0||b==0)
	return 0;
	
	if(dp[a][b]!=-1)
	return dp[a][b];
	
	else if(s1[a-1]==s2[b-1])
	return dp[a][b]=1+lcs(a-1,b-1);
	else
	return dp[a][b]=max(lcs(a,b-1),lcs(a-1,b));	
	
}
int main()
{ int len1,len2;
	while(scanf("%s",s1)!=EOF&&scanf("%s",s2)!=EOF)
	{
		len1=strlen(s1);
		len2=strlen(s2);
		memset(dp,-1,sizeof dp);
		printf("%d",lcs(len1,len2));
		
	}
	return 0;
}
