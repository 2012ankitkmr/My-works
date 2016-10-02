#include<bits/stdc++.h>
using namespace std;
double a[10004],sum;
int main()
{
	int n,test,k;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
	scanf("%lf",&a[i]);
	sort(a,a+n);
	sum=0.0;
		for(int i=k;i<n-k;i++)
		{
			sum+=(a[i]);
		}
		sum/=(double)(n-2*k);
		printf("%lf\n",sum);
	}
	
	return 0;
}
