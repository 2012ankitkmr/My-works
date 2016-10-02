#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test,n,index_max_b;
	long long ans,a[100005],b[100005],k,max_b;
	for(scanf("%d",&test);test--;)
	{
		scanf("%d%lld",&n,&k);
		for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
		max_b=-1;
		for(int i=0;i<n;i++)
		{
		scanf("%lld",&b[i]);
        if(max_b<abs(b[i]))
        {
        max_b=abs(b[i]);
        index_max_b=i;
        }
        }
        if(b[index_max_b]<0)
        a[index_max_b]-=k;
        else
        a[index_max_b]+=k;
        ans=0;
        for(int i=0;i<n;i++)
        ans+=(a[i]*b[i]);
printf("%lld\n",ans);	
	
	}
	
	
	
	return 0;
}
