#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll x,y,n;
	cin>>n;
	
	if(n==1||n==2)
	printf("-1\n");
	else
	{
		if(n&1)
		{
			y = n*n;
			y-=1;
			y/=2;
			x = y+1;
		}
		else
		{
			y = n*n;
			y/=2;
			y-=2;
			y/=2;
			x= y+2;
		}
		printf("%lld %lld\n",y,x);
	}
	
	return 0;
}
