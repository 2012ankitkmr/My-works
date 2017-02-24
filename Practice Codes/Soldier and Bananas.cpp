#include<bits/stdc++.h>
using namespace std;

long long k,n,w;
int main()
{
	scanf("%lld%lld%lld",&k,&n,&w);
	
	w = w*(w+1);
	w>>=1;
	long long ans = w*k;
	if(ans<=n)
	{
		printf("0\n");
	}
	else
	printf("%lld\n",ans-n);
	
	
	
	return  0;
}
