#include<bits/stdc++.h>
using namespace std;

int n,t;
double p;
double dp[2003][2003];

double compute(int time,int person,double prev)
{

	if(time>t||person>n)
	return 0.0;
	
	if(time==t&&person==n)
	return prev;
		
	if(fabs(dp[time][person]-(-1.0))>1e-6)
	return 0.0;

//	printf("%d %d\n",time,person);
	
	double ans = 0.0;
	if(time>0&&person>0)
	ans = prev;
	ans+=compute(time+1,person+1,prev*p);
	ans+=compute(time+1,person,prev*(1-p));
	return dp[time][person]=ans;
}


int main()
{
scanf("%d%lf%d",&n,&p,&t);

double sum= 0.0;
dp[0][0]=1.0;
for(int i = 1; i <= t; i++)
	{
		for(int j = 0; j <= i&&j<=n ; j++)
		{
			if(j < n)
			{
				dp[i][j] = dp[i-1][j] * (1 - p);
			}
			else dp[i][j] = dp[i-1][j];
			if(j > 0) dp[i][j] = dp[i][j] + dp[i -1][j - 1] * p;
		}
	}
	for(int i = 1; i <= n;i++)
	{
		sum = sum + dp[t][i] * i;
	}
	cout<<fixed<<setprecision(10)<<sum<<endl;
//	memset(dp,-1.0,sizeof dp);
//	cout<<compute(0,0,1);
	
	return 0;
}
