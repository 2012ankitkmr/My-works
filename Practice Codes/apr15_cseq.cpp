#include <stdio.h>
#include<iostream>
using namespace std;
#define ll unsigned long long
 
 
 /*
 long long int fast_multiplication(long long a, long long b) // a * b % c
 
{
 
  if (b == 0) {  //Base case a * 0 =0
 
      return 0;
  }
 
  long long ret = fast_multiplication(a, b >> 1);  //Multiply a by (b>>1).
 
  ret = (ret + ret) % 1000003;  //we double the value of ret i. 2 * (a * (b>>1)). Take MOD in this step
 
  if (b & 1) {  //trickplies b is ODD
 
      ret = (ret + a) % 1000003;  //if b is odd then we express it as a * b = a+ a * (b>>1). We have computed a*(b>>1) in the previous step by recursion i.e the value ret. We now add the extra a to it.
  }
 
  return ret;
}
*/
ll countFact(ll n, ll p)
{
    ll k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 
/* This function calculates (a^b)%MOD */
ll pow(ll a, ll b, ll MOD)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=((x%MOD)*(y%MOD))%MOD;
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n,ll MOD)
{
    return pow(n,MOD-2,MOD);
}
 
 ll factMOD(ll n,ll MOD)
{
    ll res = 1;
    while (n > 0)
    {
        for (ll i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}
 
ll combination( ll n, ll r,ll MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
/*
long long int fast_multiplication(long long a, long long b)
{
	return ((a % 1000003) * (b % 1000003)) % 1000003;
}
 long long pow(long long a, long long b){
	long long temp,k;
	
	if(b==0)	
		return 1;
	else
	{ 
		temp=pow(a,b/2);
			//printf("temp=%lld\n",temp);
		if(b%2)	
			{ k=fast_multiplication(a,(fast_multiplication(temp,temp)));
			//printf("k=%lld\n",k);
			return k;
}
		else
			return fast_multiplication(temp,temp);
	}
}
 
 
long long powr(long long  int a,long long int n){	// calc a^n (mod M)
	long long int r=1;
	for(long long int x=a;n;n>>=1,x=fast_multiplication(x,x))
	 if(n&1)
	  r=fast_multiplication(r,x);
	return r;
}
 
llu trick(llu arg)
{
    return pow(arg,1000003-2);
}
 
 
llu combination(llu n, llu r)
{
	llu i;
   
 	llu numr = 1;
    for ( i=0; i<r; i++) {
       numr= fast_multiplication(numr,n-i);
    }
 
    llu dr = 1;
    for ( i=1; i<=r; i++) {
        dr = fast_multiplication(dr, i);
    }
 
 llu y=trick(dr);
    return fast_multiplication(numr, y );
}
*/ 
 
int main()
{
	int t;
	ll n,l,p,r,ans,net;
	for(cin>>t;t--;)
	{
 
		cin>>n>>l>>r;
		net = (r-l+1);
		p=(net + n)%1000003;
		net=net%1000003;
		n=n%1000003;
		if(net < n)
			ans = combination(p, net,1000003);
		else
			ans = combination(p, n,1000003);
		ans--;
		cout<<ans<<"\n";
	}
	return 0;
} 

