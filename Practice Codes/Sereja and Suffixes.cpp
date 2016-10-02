#include<bits/stdc++.h>
using namespace std;

int a[100005] , dp[100005],has[100005];
int main()
{
	int n , m , num;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n ; i++ )
	{
	scanf("%d",&a[i]);
	has[a[i]] = i;
}
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		if(has[a[i]] > i)
		dp[i] = dp[i + 1];
		else
		dp[i] = dp[ i + 1 ] + 1;
	}
	
//	for(int i = 0 ; i < n ; i++ )
///	printf("%d ",dp[i]);
//	printf("\n");
	for(int i = 0; i < m ;i++ )
	{
		scanf("%d",&num);
	printf("%d\n",dp[num-1]);
    }
	return 0;
}
