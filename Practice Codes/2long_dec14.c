#include<stdio.h>

int main(){
	long int n,q,b,l,i,j,c,a;
	int k,m,flag,count;
	long int x[10000],y[10000],z[10000],p[10000];
	scanf("%d%d",&n,&k);
	scanf("%d",&b);
	
	for(i=1;i<=(n-1);i++)
	{
	scanf("%d%d",&x[i],&y[i]);	
	}

	for(i=1;i<=n;i++)
	{
		scanf("%d",&z[i]);
	}
	p[1]=b;
	j=2;	
	for(i=1;i<=n;i++)
	{
		if(x[i]==b)
		p[j++]=y[i];
		if(y[i]==b)
		p[j++]=x[i];
	}
	k=j;
	scanf("%d",&q);
	
	for(i=1;i<=q;i++)
	{
	scanf("%d%d",&l,&m);
	c=-1;
	for(j=1;j<=n;j++)
	{
if(z[j]==m)
{
 flag=0;
count=0; 
	{   if(l!=b){
	
		for(a=1;a<=k;a++)
		{
		if(p[a]==j)
		{
		flag=1;
		break;
		}
		}
         }
     }
		if(flag==0&&j!=b)
		{
		c=j;
		break;
	    }                                           //case 1-when j==b and further anticip. for a better farther number	                                            // case 2 when flag==1 and going to the lowest value.
	else{
		if(count==0)
	      c=j;	
	count++;
	}
	}
	}
		printf("%ld\n",c);	
	}
	
	return 0;
}
