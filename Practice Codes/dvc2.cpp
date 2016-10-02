#include<stdio.h>
int main()
{
freopen("in.txt","r",stdin);
int t,n,i,x,j,s,l;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);

int a[n*n+n],b[n+n];

for(i=0;i<n*n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
s=0,j=0;
while(j<n*n)
{
s+=a[i+j];
//printf("%d\n",a[i+j]);
j+=(n);
}

b[i]=s;
}
for(i=0;i<n;i++)
printf("%d ",b[i]);
printf("\n");
}
return 0;
}
