#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define M 1000000007
using namespace std;
long long int a1[100006];
long long int a2[100006];
long long int t,n,i,j,sum,a,b,k,ex,ba;
 
int main()
{
for(i=0;i<100004;i++)
  a2[i]=1;
	for(i=0;i<100004;i++)
  {
ex=i;
ba=2;
    while (ex)
    {
        if (ex & 1)
            a2[i] =((a2[i])%M*(ba)%M)%M;
        ex >>= 1;
        ba = ((ba)%M*(ba)%M)%M;
    }
 }
 
cin>>t;
while(t--)
{
sum=0;
a=0;
b=0;
cin>>n;
for(i=0;i<n;i++)
{
cin>>a1[i];
}
sort(a1,a1+n);
for(i=0;i<n;i++)
{
k=(a2[i]-1)%M;
a=(a%M+((a1[i])*k)%M)%M;
}
for(i=0;i<n;i++)
{
k=(a2[n-1-i]-1)%M;
b=((b)%M+((a1[i])*k)%M)%M;
}
if((a-b)<0)
{
sum=((a-b)+M)%M;
}
else
sum=(a-b)%M;
printf("%lld\n",sum);
}
return 0;
} 
