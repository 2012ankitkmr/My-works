#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 10000007

ll FastPower(ll a,ll p)
{
    ll RES = 1;
    
    ll B =  a;
    while(p > 0)
    {
        if(p%2 == 1) RES = (RES*B)%MOD;
        B = (B*B)%MOD;
        p = p>>1;
    }
    ll res = RES;
    return res;
}

int main()
{
ll a,b,c,d,n,k;
while(1)
{
scanf("%lld%lld",&n,&k);
if(n==0&&k==0)
break;
a=(2*FastPower(n-1,k))%MOD;
b=(2*FastPower(n-1,n-1))%MOD;
c=FastPower(n,k);
d=FastPower(n,n);	
ll ans=(a+b+c+d)%MOD;
printf("%lld\n",ans);
}
	return 0;
}
