#include<bits/stdc++.h>
using namespace std;
char s[27];
int dp[30][300];
int len;
int compute(int pos,int prevsum)
{
	if(pos==len)
	return 1;
	if(dp[pos][prevsum]!=-1)
	return dp[pos][prevsum];
	int sum=0;
	int c=0;
	for(int i=pos;i<len;i++)
	{
		sum+=s[i]-'0';
		if(sum>=prevsum)
		c+=compute(i+1,sum);
	}
	return dp[pos][prevsum]=c;
}

int main()
{ int t=0;
	while(1)
	{
		scanf("%s",s);
		if(s[0]>'9')
		break;
		 len=strlen(s);
		memset(dp,-1,sizeof dp);
	int ans=compute(0,0);
		printf("%d. %d\n",++t,ans);
	}	
	return 0;
}
