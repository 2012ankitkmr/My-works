#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	long long n,c,ans;
	for(scanf("%d",&test);test--;)
	{
		scanf("%lld",&n);
		c=1;
while(c<=n)
c<<=1;
ans=((n-(c>>1))<<1)+1;
printf("%lld\n",ans);
		
	}
	
	return 0;
}
