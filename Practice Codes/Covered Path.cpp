#include<bits/stdc++.h>
using namespace std;
int a,b,t,d;
int dp[125][1125];
int compute(int time,int speed)
{
	if(time==t-1)
	{
		
		if(speed==b)
		{
	//		printf("here\n");
		return speed;
	    }
		else
		return INT_MIN;
	}
	
	if(dp[time][speed]!=-1)
	return dp[time][speed];
	
	int ans=INT_MIN;
	
	for(int i = -1*d; i<=d ;i++)
	{
		if(speed+i>=0)
		ans = max(ans,speed + compute(time+1,speed+i));
	}
	
	return dp[time][speed] = ans;
}



int main()
{
	scanf("%d%d",&a,&b);
	scanf("%d%d",&t,&d);
	
	memset(dp,-1,sizeof dp);
	printf("%d\n",compute(0,a));
	
	return 0;
}
