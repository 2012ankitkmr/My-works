#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a[502];
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	
	int ans=0;
	for(int i= 1;i<n;i++)
	{
		if((a[i-1]+a[i])<k)
		{
			ans += ((k-a[i-1])-a[i]);
			a[i]=k-a[i-1];
		}
	}
	printf("%d\n",ans);
	for(int i  =0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
