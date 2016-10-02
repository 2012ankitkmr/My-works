#include<stdio.h>
int main()
{
	int t,flag;
	long int n,count,a[10004],i,b;
	for(scanf("%ld",&t);t--;)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
		count=0;
		b=a[1];
		flag=1;
		for(i=2;i<=n;i++)
      {  if(b!=a[i])
      {
      if(flag)
	  count+=2;
	  else
	  count++;
b=a[i];
flag=0;
      }
      else
      {
      	flag=1;
      }
	
      }
		printf("%ld\n",count);
	}
	
	return 0;
}
