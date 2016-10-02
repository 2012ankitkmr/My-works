#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
long long int n,ref=0;
	for(int i=0;i<=36;i++)
	{
		ref=ref*2+((i&1)?0:1);
	}
	//printf("%lld\n",ref);
	for(scanf("%d",&test);test--;)
	{
		scanf("%lld",&n);
		printf("%lld\n",n&ref);	
	}		
	return 0;
}
