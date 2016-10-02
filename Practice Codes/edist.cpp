#include<stdio.h>
#include<string.h>
char string1[2004],string2[2004];
int dp[2005][2005];
int min(int a,int b)
{
	return a<b?a:b;
}
 int edit_distance(int l1,int l2)
{
	
	int m,i,j;
	for(i=0;i<=l1;i++)
	dp[i][0]=i;
	for(i=0;i<=l2;i++)
	dp[0][i]=i;
	
	for(i=1;i<=l1;i++)
{
for(j=1;j<=l2;j++)
{
	m=min(dp[i-1][j],dp[i][j-1])+1;
	dp[i][j]=min(m,dp[i-1][j-1]+(string1[i-1]==string2[j-1]?0:1));
}
}

return dp[l1][l2];	
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
	
	scanf("%s",string1);
	scanf("%s",string2);	
		
		printf("%d\n",edit_distance(strlen(string1),strlen(string2)));
	}
	return 0;
}
