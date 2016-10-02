#include<stdio.h>

int main(){
	long int i,n,x,y,c,d,sum;
	int a[100005],b[100005];
	scanf("%ld%ld%ld",&n,&x,&y);
	c=d=0;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	scanf("%d",&b[i]);
	sum=0;
	
	for(i=n;i>=1;i--)
	{
		if(a[i]>b[i]&&c<=x)
		{sum=sum+a[i];
		c++;	
		}
		else
		{
			sum=sum+b[i];
			d++;
		}
		
	}
	printf("%ld\n",sum);
	return 0;
}
