#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
	ll test,temp1,sum1,temp2,sum2,n;
	for(scanf("%lld",&test);test--;)
	{
		scanf("%lld",&n);
		sum1=0,sum2=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&temp1,&temp2);
			sum1+=temp1;
			sum2+=temp2;
		}
		printf("%lld\n",sum1-sum2);
		
	}
	
	return 0;
}
