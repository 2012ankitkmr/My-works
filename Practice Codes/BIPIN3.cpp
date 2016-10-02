#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long fastpow(long long a,long long pow)
{
	long long res = 1;
	long long b = a;
	while( pow > 0 )
	{
		if( pow & 1 ) res = ( res * b ) % MOD;
		b = ( b * b) % MOD;
		pow >>= 1;
	}
	return res;
}

int main()
{
	long long test,n,k,ans;
	
for( scanf("%lld",&test) ; test-- ; )
{
	scanf("%lld%lld",&n,&k);

	ans = ( k % MOD * fastpow(k-1,n-1) %MOD ) %MOD;
	printf("%lld\n",ans);
}	
	return 0;
}
