#include<stdio.h>
int a[1000],n;
int subset(int,int,int,int);
int main()
{
int i,t,j,size,c,d,k;
scanf("%d",&t);
for(j=0;j<t;j++)
{
scanf("%d%d",&size,&k);
for(i=0;i<size;i++)
scanf("%d",&a[i]);
n=size;
c=k^0;
for(i=1;i<=n;i++)
{
d=subset(0,0,i,k);
if(c<d)
c=d;
}
printf("%d\n",c);
}
return 0;
}
int subset(int start,int index,int no_of_subset,int k)
{
int i,j,c=0,d,e;
if(index-start+1==no_of_subset)
{
if(no_of_subset==1)
{
for(i=0;i<n;i++)
{
d=k^a[i];
printf("a=%d ",a[i]);
if(c<d)
c=d;
}
printf("\n");
}
else
{
for(j=index;j<n;j++)
{e=0;
for(i=start;i<index;i++)
{
printf("a=%d ",a[i]);
e=e^a[i];
}
printf("\n");
e=e^a[j];

d=k^e;
if(c<d)
c=d;
}
if(start!=n-no_of_subset)
subset(start+1,start+1,no_of_subset,k);
}
}
else
{
subset(start,index+1,no_of_subset,k);
}
return c;
}
