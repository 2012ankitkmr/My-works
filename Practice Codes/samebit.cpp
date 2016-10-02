#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int findbitset(int a)
{
int cnt=0;
while(a)
{
a=a&(a-1);
cnt++;
}
return cnt;
}
int main()
{
int t;
ll n,k;
ll num[1005];
for(scanf("%d",&t);t--;)
{
scanf("%lld%lld",&n,&k);
for(int i=0;i<n;i++)
{
scanf("%lld",&num[i]);
}
for(int i=0;i<n;i++)
{
num[i]=findbitset(num[i]);
}
sort(num,num+n);
ll ans=0;
for(int i=0;i<k;i++)
{
ans+=num[i];
}
printf("%lld\n",ans);
}
return 0;
}
