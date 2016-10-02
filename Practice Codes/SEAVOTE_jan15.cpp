#include<stdio.h>

int main()
{
	int t,i,n,b[10005],a;
	long int sum;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	
	for(i=0;i<n;i++)
	sum=sum+b[i];
	
	if(sum<100)
	printf("NO\n");
	else
	{
		a=n/2;
		if(!a%2)
		{
		if((100+a)<sum)
	     printf("NO\n");
	     else
	     printf("YES\n");
	     }
		else
		{
			if((101+a)<sum)
			printf("NO\n");
			else 
			printf("YES\n");
		}
	}
	
}
	return 0;
}
