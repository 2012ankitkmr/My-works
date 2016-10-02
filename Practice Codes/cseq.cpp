#include <stdio.h>
typedef ll unsigned long long
#define MOD 1000003
 
 
long long pm(long long a, long long b)
{
	return ((a % MOD) * (b % MOD)) % MOD;
}
 
long long pwrfun(long long x, long long y){
	long long tmp;
	if(y==0)	
		return 1;
	else
	{
		tmp=pwrfun(x,y/2);
		if(y%2)	
			return pm(x,(pm(tmp,tmp)));
		else
			return pm(tmp,tmp);
	}
}
 
ll IM(ll n)
{
    return pwrfun(n,MOD-2);
}
 
 
ll nCr(ll n, ll r)
{
	ll i;
    //if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
      //  return 0;

 	ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for ( i=0; i<r; i++) {
        numerator = pm(numerator,n-i);
    }
 
    ll denominator = 1; // k!
    for ( i=1; i<=r; i++) {
        denominator = pm(denominator, i);
    }
 
    return pm(numerator, IM(denominator) );
}
 
 
int main()
{
	int t;
	ll c,l,r,total,rng;
	scanf("%d",&t);
	while(t--)
	{
 
		scanf("%llu%llu%llu",&c,&l,&r);
		rng = (r-l+1);
		if(rng < c)
			total = nCr(rng + c, rng);
		else
			total = nCr(rng + c, c);
		total--;
		printf("%llu\n",total);
	}
	return 0;
}
