#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll getsummation(ll n)
{
	n = n*(n+1);
	return (n/2);
	
	
}

int main()
{
	int t;
	ll ans,l,r;
	
	freopen("A-large.in","r+",stdin);
	freopen("out.txt","w+",stdout);
	scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{
		scanf("%lld%lld",&l,&r);
		
		ans= getsummation(min(l,r));
		
		printf("Case #%d: %lld\n",test,ans);
		
	}
	
	return  0;
}
