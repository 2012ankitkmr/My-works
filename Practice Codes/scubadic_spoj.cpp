#include<stdio.h>
#include<map>
#include<string.h>
#define MAX 100000005
typedef long long int lli;

lli ox[1005],ni[1005],wt[1005];
lli best[1005][23][82];

lli min(lli a,lli b)
{
	
	return a>b?b:a;
}

lli min_wt(lli n,lli oxygen,lli nitrogen)
{
lli i,j,k;
memset(best,0,sizeof(best));
for(k=0;k<=n;++k)
{
	for(i=0;i<=21;++i)
	{
		for(j=0;j<=79;++j)
		{
			if(k==0)
			{
				best[k][i][j]=MAX;
				if(i==0&&j==0)
				best[k][i][j]=0;
			}
			else
			{
				best[k][i][j]=min(best[k-1][i][j],wt[k]+best[k-1][(i-ox[k])<=0?0:(i-ox[k])][(j-ni[k])<=0?0:j-ni[k]]);
			}
			
		}
		
	}
	
	
}
return best[n][oxygen][nitrogen];
	
}

int main()
{
	lli i,t,n,req_o,req_n;
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld%lld",&req_o,&req_n);
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
	scanf("%lld%lld%lld",&ox[i],&ni[i],&wt[i]);
	}
	
	printf("%lld\n",min_wt(n,req_o,req_n));
	}
	
	return 0;
}
