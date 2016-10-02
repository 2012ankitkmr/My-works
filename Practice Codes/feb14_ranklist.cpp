#include<stdio.h>

int main()
{
	int t;
	long long int i,s,n,ans,sum;
	
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld%lld",&n,&s);
		sum=n;
		for(i=2;i<=n;++i)
		{
		
		if(sum+i-1>s)
		{ans=n-i+1;
		break;
		}
			sum+=(i-1);	
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
