#include<bits/stdc++.h>
using namespace std;


int dp[202][202][202];
int precompute(int a,int b,int c)
{
if(a<0||b<0||c<0)
return 0;

if(dp[a][b][c]!=-1)
return dp[a][b][c];

int ans=0;
			ans = precompute(a-1,b-1,c+1)|precompute(a-1,b+1,c-1)|precompute(a+1,b-1,c-1);
			if(a>=2)
			ans|= precompute(a-1,b,c);
			if(b>=2)
			ans|= precompute(a,b-1,c);
			if(c>=2)
			ans|= precompute(a,b,c-1);

return dp[a][b][c]=ans;	
}

int main()
{
	memset(dp,-1,sizeof dp);
	int n;
	char s[202];
	scanf("%d",&n);
	scanf(" %s",s);
	dp[1][0][0]=4;
	dp[0][1][0]=2;
	dp[0][0][1]=1;
	dp[0][1][1]=4;
	dp[1][1][0]=1;
	dp[1][0][1]=2;
	

	for(int i = 1;i<=200;i++)
	{
	dp[i][0][0]=4;
	dp[0][i][0]=2;
	dp[0][0][i]=1;
    }
	
for(int i = 1;i<=200;i++)
{
	for(int j = 1;j<=200;j++)
	{
		for(int k = 1;k<=200;k++)
		{
			dp[i][j][k]=7;
		}

	}
}

int R=0,B=0,G=0;

for(int i = 0;i<n;i++)
{
	if(s[i]=='R')
	R++;
	else if(s[i]=='G')
	G++;
	else
	B++; 
}

int ans= precompute(R,G,B);
	if(ans&1)
	printf("B");
	if(ans&2)
	printf("G");
	if(ans&4)
	printf("R");

	return  0;
}
