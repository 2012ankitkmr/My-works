#include<bits/stdc++.h>
using namespace std;
bool comp(const long long &a,const long long &b)
{
	return a>=b;
}

int main()
{
	long long test,k,a[4];
	long long ans;

	for(scanf("%lld",&test);test--;)
	{
		ans=0;
		scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
		scanf("%lld",&k);
		sort(a,a+3,comp);
		if(a[2]>=k)
		{
			ans=(k-1)*3+1;
		}
		else
		{
			k-=a[2];
			a[0]-=a[2];
			a[1]-=a[2];
		
			ans+=(3*a[2]);
			if(a[1]>=k)
			{
				ans+=(k-1)*2+1;
			}
			else
			{
				k-=a[1];
				a[0]-=a[1];
				ans+=(2*a[1]);
				ans+=(k-1)*1+1;
				//printf("%d\n",k);
			}
			
		}
		
		printf("%lld\n",ans);
	}
	
	return  0;
}
