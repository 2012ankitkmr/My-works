#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 100000000

ll dp[102][102][3][12];
int n1,n2,k1,k2;

ll compute(int cnt1,int cnt2 ,int current,int streak)
{
	if(cnt1>n1)
	return 0;
	if(cnt2>n2)
	return 0;
	
	if((cnt1+cnt2)==(n1+n2))
	{
		if(cnt1==n1&&cnt2==n2)
		return 1;	
		else
		return 0;
	}
	
	if(dp[cnt1][cnt2][current][streak]!=-1)
	return dp[cnt1][cnt2][current][streak];
	
	ll ans =0;
	
	if(current==1)
	{
		if(streak<k1)
		ans = (ans+compute(cnt1+1,cnt2,current,streak+1))%MOD;
		
		ans = (ans+compute(cnt1,cnt2+1,2,1))%MOD;
	}
	if(current==2)
	{
		if(streak<k2)
		ans = (ans+compute(cnt1,cnt2+1,current,streak+1))%MOD;
		ans = (ans+compute(cnt1+1,cnt2,1,1))%MOD;
	}
	
	return dp[cnt1][cnt2][current][streak]=ans;
}


int main()
{
memset(dp,-1,sizeof dp);
scanf("%d%d%d%d",&n1,&n2,&k1,&k2);

ll ans = (compute(1,0,1,1)+compute(0,1,2,1))%MOD;	
	cout<<ans;
	return 0;
}
