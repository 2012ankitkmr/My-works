#include<stdio.h>
int main()
{
	freopen("in.txt","r",stdin);
int t,n,i,x=0,y;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
y=0;
i=1;
x=0;
while(n!=0)
{
if((n&1)&&(x==0))
{
x=i;
}
if(n&1)
y=i;
i=i<<1;
n=n>>1;
}
if(x!=y)
printf("%d %d\n",x,y);
else
printf("%d %d\n",0,y);
}
return 0;
}
