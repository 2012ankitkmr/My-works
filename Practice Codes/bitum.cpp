#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int findbitset(ll a)
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
ll m,p;
for(scanf("%d",&t);t--;)
{
scanf("%lld%lld",&m,&p);
for(int i=0;i<n;i++)
{
num[i]=findbitset(num[i]);
}
}
return 0;
}
