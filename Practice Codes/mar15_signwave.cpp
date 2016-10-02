#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	int s,c,k;
	long long int p,i;
	for(scanf("%d",&t);t--;)
	{
		
	scanf("%d%d%d",&s,&c,&k);
    if(c>=s)
    {
    p=1<<(s-k+1);	
    p++; 	
    if(k==1)
	{
	for(i=1;i<=c;i++)
	p=p+1<<i;
    }
	}
else
{
p=1<<(s-k+1);
p++;



}

printf("%lld\n",p);
	}
	
return 0;
}
