#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,a[100005],m,l,r,dp[100005],dps[100005],ch;
	
int main()
{
	
	cin>>n;
	for(int i = 1;i<=n;i++)
	cin>>a[i];
	dp[0]=0,dps[0]=0;
	for(int i = 1;i<=n;i++)
	dp[i]=dp[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	dps[i]=dps[i-1]+a[i];
	
	for(cin>>m;m--;)
	{
		cin>>ch>>l>>r;
		if(ch==1)
		cout<<dp[r]-dp[l-1]<<endl;
		else
		cout<<dps[r]-dps[l-1]<<endl;
		
	}
	
	
	return  0;
}
