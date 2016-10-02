#include<bits/stdc++.h>
using namespace std;

char s1[1005],s2[1005];
long int dp[1002][1002];
long int edit_distance1()
{
	
//memset(dp,0,sizeof dp);
	int len=strlen(s1);
	int len2=strlen(s2);
	for(int i=0;i<=len;i++)
	dp[i][0]=i*15;
	for(int i=0;i<=len2;i++)
	dp[0][i]=i*30;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len2;j++)
		{
		if(s1[i-1]==s2[j-1])
		dp[i][j]=dp[i-1][j-1];
		else
		dp[i][j]=min(dp[i][j-1]+30,dp[i-1][j]+15);
		
		}
		
	}
	return dp[len][len2];
}




int main()
{
	while(1)
	{
	
	scanf("%s",s1);
	if(s1[0]=='#')
break;
	scanf("%s",s2);		
	printf("%ld\n",edit_distance1());	
}
	return 0;
}
