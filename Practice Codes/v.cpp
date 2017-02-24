#include<bits/stdc++.h>
using namespace std;

int main()
{
	ll x,y;
	int n;
	cin>>n;
	
	if(n==1||n==2)
	printf("-1\n");
	else
	{
		if(n&1)
		{
			y = (ll)n*(ll)n;
			y-=1;
			y/=2;
			x = y+1;
		}
		else
		{
			y = (ll)n*(ll)n;
			y/=2;
			y-=2;
			y/=2;
			x= y+2;
		}
		printf("%d %d\n",x,y);
	}
	
	return 0;
}
