#include<stdio.h>
int func(int a[],int n,int m,int x,int y)
{
int z,c=-1;
printf("%d%d\n",x,y);
if(x<=y){
z=(x+y);
z=z/2;
if(m%a[z]==0){
c=z;
}
else if(m<a[z])
{
return func(a,n,m,x,z);
}
else
return func(a,n,m,z+1,y);
}
else
return c;
}
int main()
{
int t,i,n,m,c,q;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
n--;
scanf("%d",&q);
while(q--) {
scanf("%d",&m);
c=func(a,n+1,m,0,n);
printf("%d\n",c);
}
return 0;
}
