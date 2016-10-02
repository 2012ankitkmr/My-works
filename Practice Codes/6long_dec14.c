#include<stdio.h>
#include<math.h>
int main()
{int i,t,x[400],y[400],j,p,k,c,n;
scanf("%d",&t);
double d[400][400],dmin;

for(i=0;i<t;i++)
{
	scanf("%d",&n);
	
	for(j=1;j<=n;j++)
	scanf("%d%d",&x[j],&y[j]);
	

	for(j=1;j<=n-1;j++)
	{
		for(k=j+1;k<=n;k++)
		d[j][k]=sqrt(pow((x[k]-x[j]),2)+pow((y[k]-y[j]),2));
	}
	for(j=2;j<=n;j++)
	{
		for(k=1;k=n;k++)
		{
			if(j>k)
			d[j][k]=d[k][j];
			else
			break;		
		}
		
	}
	for(j=1;j<=(n-1);j++)
{
	dmin=d[j][j+1];
	c=k;
	for(k=1;k<=n;k++)
	{
		if(k!=j)
		{
			if(dmin>=d[j][k])
			{
               if(k!=p)
               c=k;
			}
		}
		
	}

	p=j;

printf("%d %d\n",j,c);	
}

}
	return 0;	
}
