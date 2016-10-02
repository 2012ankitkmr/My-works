#include <bits/stdc++.h>
using namespace std;


char ch[1003];
long long num[1003];
int main()
{
long long  sum = 0,n,k;
cin>>n>>k;


for(int i = 0 ;i <n;i++)
{
cin>>ch[i];
cin>>num[i];
}

sum  = k;
long long  distress = 0;
for(int i = 0 ;i<n;i++)
{
if(ch[i]=='+')
sum+=num[i];
else
{
if(sum<num[i])
distress++;
else
{
  sum-=num[i];
}
}

}
cout<<sum<<" "<<distress;


  return 0;
}
