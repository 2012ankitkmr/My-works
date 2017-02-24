#include<bits/stdc++.h>
using namespace std;

long long n,m,x,y,a;
int main()
{
	cin>>n>>m>>a;
	
	x=n/a;
	if(n%a)
	x++;
	y=m/a;
	if(m%a)
	y++;
	printf("%lld\n",x*y);
	return 0;
}
