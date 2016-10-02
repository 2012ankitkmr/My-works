#include<stdio.h>
#include<string.h>
 unsigned long long int ans[1004];
unsigned long long int max(unsigned long long int a,unsigned long long int b)
{
	return a>b?a:b;
}
int main()
{
 long int i,j=0,t,n,k;

	for(scanf("%ld",&t);t--;)
	{
		j++;
		scanf("%ld",&n);
		
		for(i=0;i<n;i++)
		{
		scanf("%lu",&k);
			 ans[i]=max(k+(i>1?ans[i-2]:0),i>0?ans[i-1]:0);
		}
		
		printf("Case %d: %llu\n",j,ans[n-1]);
		
	}
	return 0;
}
