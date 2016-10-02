#include<bits/stdc++.h>
using namespace std;


char s[105];
vector<char> ans;
int dp[111][11];
int n;
bool compute(int pos,int prevnum)
{
	if(pos==n)
	return 0;
	
	if(dp[pos][prevnum]!=-1)
	return dp[pos][prevnum];
	
//	printf("%d %d\n",pos,prevnum);
	int num = 10*prevnum+s[pos]-'0';
	num = num%8;
	

	if(num==0)
	{
		ans.push_back(s[pos]);
		return dp[pos][prevnum] = 1;
	}
	
	for(int i = 1;i <= n ;i++)
	{
	
	
	if(i+pos<=n)
	{	
	if(compute(pos+i,num)==1)
	{
	ans.push_back(s[pos]);
	return dp[pos][prevnum] = 1;	
	}
	
	if(compute(pos+i,prevnum)==1)
	{
	return dp[pos][prevnum] = 1;	
	}
	}
   }
return dp[pos][prevnum]=0;
}



int main()
{
	scanf(" %s",s);
	n = strlen(s);
	
	memset(dp,-1,sizeof dp);
	
	if(compute(0,0))
	{
		printf("YES\n");
		for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i];
}
else
printf("NO\n");
	return  0;
}
