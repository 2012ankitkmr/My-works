#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll exp(ll a,ll p,ll MOD)
{
    ll RES = 1;
    ll B = (ll) a;
    while(p > 0)
    {
        if(p%2 == 1) RES = (RES*B)%MOD;
        B = (B*B)%MOD;
        p = p/2;
    }
    ll res =  RES;
    return res;
}


int main()
{
	
	int t;
	freopen("B-small-practice.in","r+",stdin);
	freopen("out.txt","w+",stdout);
	ll a,b,n,k,cnt,val2,val1;
	scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&n,&k);
		cnt= 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i==j)
				continue;
				
				val1 = exp(i,a,k);
				val2 = exp(j,b,k);
				if((val1+val2)%k==0)
				{
					cnt++;
				}
			}
			
		}
		printf("Case #%d: %lld\n",test,cnt);
		
		
	}
	
	return  0;
}
