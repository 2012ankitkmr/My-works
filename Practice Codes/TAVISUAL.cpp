#include<stdio.h>
int main()
{
	int t,i;
	long int a,j,n,c,q,l[10000],r[10000];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		
		scanf("%d%d%d",&n,&c,&q);
		
		for(j=1;j<=q;j++)
		scanf("%d%d",&l[j],&r[j]);
		
		for(j=1;j<=q;j++)
		{
		a=c-l[j];
		if(a>=0&&(r[j]-l[j])>=a)	
		{c=r[j]-a;
		}	
		//printf("%d\n",c);	
		}
		printf("%ld\n",c);
	}
	return 0;
}
