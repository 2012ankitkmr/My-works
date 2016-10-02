#include<bits/stdc++.h>

int a[500];

bool isSubsetsum(int n,int c)
{
int dp[n+1][c+1];
int i,j;
memset(dp,0,sizeof dp);	

for(i=1;i<=n;i++)
{
for(j=1;j<=c;j++)
{
dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i]];
}	
	
}
return dp[n][c];
}
int main()
{
int t,i,n,c;
for(scanf("%d",&t);t--;)
{
	scanf("%d%d",&n,&c);

for(i=1;i<=n;i++)
{
	scanf("%d",&a[i]);	
}
if(isSubsetsum(n,c))
printf("YES\n");
else
printf("NO\n");
}
return 0;	
}
