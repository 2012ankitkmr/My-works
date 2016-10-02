#include<bits/stdc++.h>
using namespace std;

char s[100005];
int main()
{
	int len , l , r , dp[100005] , m ;
	scanf("%s",s);
	len = strlen(s);
	dp[0] = 0;
	for(int i = 1 ; i < len ; i++)
	if(s[i]==s[i-1])
	dp[i] = 1;
	else
	dp[i] = 0;
	
	for(int i = 1 ; i < len ; i++ )
	dp[i] = dp[i] + dp[i - 1];
	
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		
		printf("%d\n",dp[r-1] - dp[l-1]);
		
	}
	return 0;
}
