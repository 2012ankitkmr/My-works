#include<stdio.h>
typedef long long int ll;
ll u[10000007];
ll p[100005];
int main() {
	ll n,MOD;
	ll i;
	scanf("%lld%lld",&n,&MOD);
	u[0]=1;
	for(i=1;i<10000006;++i)
	{
		u[i]=u[i-1]*i;
		if(u[i]>=MOD)u[i]%=MOD;
	}
	ll ans = 0;
	for(i=0;i<n;++i)
	{
		scanf("%lld",&p[i]);
		if(MOD==1){
	   printf("0\n");
		continue;
		}
		else if(MOD==2)
		{
			if(((p[i]+1)&3)==0 || (p[i]&1)==0){
			ans+=1;}
 
		}
		if(MOD&1)
		{
		bool greater=p[i]>=MOD-1;
		if(p[i]>=MOD)
		p[i]%=MOD;
		ll f = u[p[i]+1];
		--f;
		if(f<0)
		f+=MOD;
		ll G = p[i]*p[i];
		if(G>=MOD)
		G%=MOD;
		G*=p[i]+1;
		if(G>=MOD)
		G%=MOD;
		if(MOD&1)
		G*=(MOD+1)/2;
		else G/=2;
		if(G>=MOD)
		G %= MOD;
		if(greater)
		f=G-1; 
		else f = f+G;
		while(f>=MOD)
		f-=MOD;
		while(f<0)
		f+=MOD;
		ans +=f;
		while(ans>=MOD)
		ans-=MOD;}
		else
		{bool greater=p[i]>=MOD-1;
		ll temp1=p[i];
		if(temp1>=MOD)
		temp1 %= MOD;
		if(p[i]>=2*MOD)
		p[i]%=2*MOD;
		ll f = u[temp1+1];
		--f;
		if(f<0)
		f+=2*MOD;
		ll G = p[i]*p[i];
		if(G>=2*MOD)
		G%=2*MOD;
		G*=p[i]+1;
		if(G>=2*MOD)
		G%=2*MOD;
		if(MOD&1)
		G*=(MOD+1)/2;
		else G/=2;
		if(G>=MOD)
		G %= MOD;
		if(greater)
		f=G-1; 
		else f = f+G;
		while(f>=MOD)
		f-=MOD;
		while(f<0)
		f+=MOD;

		ans +=f;
		while(ans>=MOD)
		ans-=MOD;}
	}
	printf("%lld\n",ans);
 
	return 0;
}
