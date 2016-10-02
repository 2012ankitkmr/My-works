#include<stdio.h>
#include<math.h>
int main()
{
int t,i;
scanf("%d",&t);
long long unsigned int a[1005],c,j;
long long unsigned int n,m,l,r,count,k,b[1005],p;
for(i=0;i<t;i++)
{
scanf("%d%d%d%d",&n,&m,&l,&r);
for(k=m;k>=1;k--)
{
count=0;	
j=k;
p=0;
while(1)
{
	j=j+k;
	count++;
	if(j>m)
	break;
b[p++]=j;		
}
if(count!=1)
a[k]=pow(count,n);
else
a[k]=1;

for(j=0;j<p;j++)
{
	a[k]-=a[b[j]];
}

}
c=0;
for(k=l;k<=r;k++)
{
	c=c+a[k];
}

printf("%llu\n",c%1000000007);
}
		
return 0;	
}
