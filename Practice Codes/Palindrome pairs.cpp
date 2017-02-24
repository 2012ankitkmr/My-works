#include<bits/stdc++.h>
using namespace std;
#define ll long long 

char s[2003];


bool checkPalin(int a,int b)
{
int lp =a,rp=b;

while(lp<rp)
{
	if(s[lp]!=s[rp])
	return false;
	lp++;
	rp--;
}
return true;
}

int adj[2003][2003];
int dp[2003][2003];

int main()
{
	scanf("%s",s);
	int n = strlen(s),lp,rp;
	ll ans = 0;

	memset(adj,0,sizeof adj);
	memset(dp,0,sizeof dp);
for(int i = 0;i<n;i++)
{
	for(int j = i;j<n;j++)
	{
		if(!adj[i][j])
		{
			if(checkPalin(i,j))
			{
			adj[i][j]=1;
			lp = i+1;
			rp = j-1;
			while(lp<rp)
			{
				adj[lp][rp]=1;
				lp++;
				rp--;				
			}	
			}
			
		}
	}
}
int cnt[2003];



for(int i = n-1;i>=0;i--)
{
	for(int j = i;j<n;j++)
	{
		
		dp[i][j] = adj[i][j]+ dp[i+1][j];
	}
}

for(int i = 0;i<n;i++)
cnt[i] = dp[0][i];

for(int i = n-1;i>=0;i--)
{
	for(int j = n-2;j>=i;j--)
	{
		dp[i][j] = dp[i][j] + dp[i][j+1];
	}
}	

for(int i = 0;i<n;i++)
{
//	printf("%d ",cnt[i]);
	ans+=cnt[i]*dp[i+1][i+1];

}
	cout<<ans;
	
	return  0;
}
