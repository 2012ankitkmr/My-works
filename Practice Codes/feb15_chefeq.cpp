#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	long int a[100006],n,i,b,max,c;
	for(scanf("%ld",&t);t--;)
{
scanf("%ld",&n);
max=0;
memset(a,0,400024);
for(i=1;i<=n;i++)
{
	scanf("%ld",&b);
	a[b]++;
	if(b>max)
	max=b;
	}
c=a[1];
for(i=1;i<=max;i++)
{	
	if(a[i]>c)
	{
		c=a[i];
	}
}	
	
printf("%ld\n",n-c);	
}
return 0;	
}
