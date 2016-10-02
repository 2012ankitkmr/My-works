#include<bits/stdc++.h>
#define M 1000000000
int main()
{
	int t,m,n;
	long long int i,sum;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m);
		
		sum=n;
		for(i=1;i<m;i++)
		{
			sum=((sum%M)*(n%M))%M;
		}
		long long int p;
		sum=(sum+1)%M;
		p=sum;
		printf("p%lld\n",p);
		for(i=1;i<m;i++)
		sum=(p%M*sum%M)%M;
		printf("%lld\n",sum);
		
	}
	return 0;
}
