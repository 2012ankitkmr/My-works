#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	ll t,cnt0,cnt1,fee,a,n;
	for(scanf("%lld",&t);t--;)
	{
	cin>>n;
	cnt0=0,cnt1=0,fee=0;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld",&a);
		if(!a)
		cnt0++;
		else
		cnt1++;
		if(cnt1<i)
		fee++;
	}	
		
		cout<<(fee*100+cnt0*1000)<<endl;
	
	}
	
	return 0;
	
}
