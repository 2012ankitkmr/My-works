#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000009
ll dp[102][102][2];
int a[200005];

ll fpow(ll a,ll p)
{
    ll RES = 1;
    ll B = (ll) a;
    while(p > 0)
    {
        if(p%2 == 1) RES = (RES*B)%MOD;
        B = (B*B)%MOD;
        p = p/2;
    }

    return RES;
}
int main()
{
	
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	scanf("%d",&a[i]);
	
	ll ans;

/*	for(int i = 0;i<n;i++)
	{
		dp[a[i]][0][0]=dp[a[i]][0][1]=1;
	}
	*/
	memset(dp,0,sizeof dp);
	 ans=2;
	 dp[a[0]][0][0]=dp[a[0]][0][1]=1;
	for(int i = 1;i<n;i++)
	{
		dp[a[i]][0][0]=dp[a[i]][0][0]+1;
		dp[a[i]][0][1]=dp[a[i]][0][0];
		ans=(ans+fpow(2,dp[a[i]][0][1]-1))%MOD;
		for(int j = 1;j<=100;j++)
		{
			if((a[i]-j)>=1)
			dp[a[i]][j][0]=(dp[a[i]-j][0][0]+dp[a[i]-j][j][0])%MOD;
			ans=(ans+dp[a[i]][j][0])%MOD;
		}
		for(int j = 1;j<=100;j++)
		{
			if((a[i]+j)<=100)
			dp[a[i]][j][1]=(dp[a[i]+j][0][1]+dp[a[i]+j][j][1])%MOD;

			ans=(ans+dp[a[i]][j][1])%MOD;
		}
	}
/*	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<=100;j++)
		{
	printf("dp[%d][%d][0] = %lld\n",i,j,dp[a[i]][j][0]);
	if(j>10)
	break;
		}
		printf("\n");
		for(int j = 1;j<=100;j++)
		{
				printf("dp[%d][%d][1] = %lld\n",i,j,dp[a[i]][j][1]);
		if(j>10)
       	break;

		}
				printf("\n");


	}
	*/
	cout<<ans<<endl;
	return 0;
}
