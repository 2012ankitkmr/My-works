#include<stdio.h>

int main()
{
	int t;
	long long unsigned int i,n,maxfact,number,div=2;
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld",&n);
		number=n;
		if(n==1)
		printf("1\n");
		else if(n==2)
		printf("3\n");
		else
    {
maxfact=0;		
for(i=2;i*i<=n;i++)
{
  if(n%i==0)
  {
if(n/i==i)
 maxfact+=i;
	else maxfact+=(i+n/i);
			}
		}
		printf("%lld\n",maxfact+n+1);
}

}	
	return 0;
}
