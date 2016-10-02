#include<bits/stdc++.h>
using namespace std;


char s[505][505];
int dp[505][505],lrdp[505][505],uddp[505][505];
int main()
{
	int n,m;
//	freopen("in.txt","r+",stdin);
	
	scanf("%d%d",&n,&m);
	
	for(int i = 1; i <= n ; i++ )
	{
	for(int j = 1; j <= m ; j++)	
		scanf(" %c",&s[i][j]);
	}
	
	
	int newbonds = 0,currentbonds = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
			if(i==1)
			{
				if(j==1)
				continue;
				if(s[i][j-1]=='.'&&s[i][j]=='.')
				{
					dp[i][j]=dp[i][j-1]+1;
				}
				if((s[i][j-1]=='.'&&s[i][j]=='#')||(s[i][j-1]=='#'&&s[i][j]=='.'))
				{
					dp[i][j]=dp[i][j-1];
				}
				
			}
			else
			{
				if(j==1)
				{
					if(s[i-1][j]=='.'&&s[i][j]=='.')
					currentbonds = 1;
					dp[i][j]=dp[i-1][j]+currentbonds;
					
				}
				else
				{
				if(s[i][j-1]=='.'&&s[i][j]=='.')
				currentbonds ++;
				if(s[i-1][j]=='.'&&s[i][j]=='.')
				currentbonds++;
		
				dp[i][j] = dp[i-1][j] + currentbonds + newbonds;								
					
				}
				
				newbonds += currentbonds;
				currentbonds=0;
				
			}
			
		}
		newbonds = 0;
		
	}

	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
     		if(j==1)
			continue;
			
				if(s[i][j-1]=='.'&&s[i][j]=='.')
					lrdp[i][j]=lrdp[i][j-1]+1;
					
				else
					lrdp[i][j]=lrdp[i][j-1];
	
				
		}
	}	
	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
     		if(i==1)
			continue;
			
				if(s[i-1][j]=='.'&&s[i][j]=='.')
					uddp[i][j]=uddp[i-1][j]+1;
					
				else
					uddp[i][j]=uddp[i-1][j];
	
				
		}
	}	
	
/*	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
		printf("%3d ",dp[i][j]);
		
				
		}
		printf("\n");

	}
	
*/
	
	
	int q,l1,l2,r1,r2;
	for(scanf("%d",&q);q--;)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		
		
		printf("%d\n",dp[l2][r2]-(dp[l2][r1]+dp[l1][r2]-dp[l1][r1])+((uddp[l2][r1]-uddp[l1][r1])+(lrdp[l1][r2]-lrdp[l1][r1])));


		
		
	}
	
	return  0;
}
