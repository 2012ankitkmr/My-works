#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e16
#define pb push_back
ll cost[1<<20];
int n,bits,m;

ll vec[19][200025];
ll sz[19];

ll dp[19][(1<<19)+2];

ll compute(ll bi,ll bitmask)
{
	if(__builtin_popcount(bitmask)==bits)
	{
		return 0;	
	}
	
	if(dp[bi][bitmask]!=-1)
	return dp[bi][bitmask];
	
	ll ans = inf,elem;

	if((1<<bi)&(bitmask))
	ans=min(ans,compute(bi+1,bitmask));
	else
	{
	for(int i = 0;i<sz[bi];i++)
	{
		elem=vec[bi][i];
	printf("%d %d\n",bi,elem);		
		ans = min(ans,cost[elem]+compute(bi+1,bitmask|elem));
		
	}
}
	return dp[bi][bitmask]=ans;
		
}

int main()
{
freopen("in.txt","r+",stdin);	
	ll t,c,p,num,bit,k;

    for(scanf("%d",&t);t--;)
  {
	memset(sz,0,sizeof sz);
	
	scanf("%d%d",&n,&m);
		bits=n;

	k = (1<<(bits));
	
	for(int i = 0;i<=k+1;i++)
	cost[i]=inf;
	
	for(int i =0;i<n;i++)
	{
		scanf("%lld",&c);
		cost[(1<<i)]=c;
		vec[i][sz[i]++]=(1<<i);
	}
	for(int i = 0;i<m;i++)
	{
		vector<ll>te;
		scanf("%lld",&c);
		scanf("%lld",&p);
		num= 0;
		for(int j = 0;j<p;j++)
		{
			scanf("%lld",&bit);
			num = num|(1<<(bit-1));
			te.pb(bit-1);
		}
			if(cost[num]==inf)
			{
			for(int j =0;j<p;j++)
			vec[te[j]][sz[te[j]]++]=num;
    	    }
			cost[num]=min(cost[num],c);

		
	}

	for(int i = 0;i<bits;i++)
	for(int j = 0;j<=k;j++)
	dp[i][j]=-1;
	//cout<<compute(1,0)<<endl;
	printf("%lld\n",compute(0,0));
}
	
	
	return 0;
}
