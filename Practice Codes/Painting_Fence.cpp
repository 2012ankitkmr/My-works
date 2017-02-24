#include "bits/stdc++.h"
using namespace std;

int compute(int a[],int l,int r,int ref)
{
  if(l==r)
  {
    return 1;
  }

int ans=0;
int minval=INT_MAX;
vector<int>vec;
for(int i = l ;i<=r;i++)
{
  minval = min(minval,a[i]);
}
for(int i = l; i <= r ;i++)
{
  if((a[i])==minval)
  vec.push_back(i);
}
int prev = l;
ans+=(minval-ref);
for(int i = 0;i<vec.size();i++)
{
  if(vec[i]-1>=prev)
  ans+=compute(a,prev,vec[i]-1,minval);
  prev = vec[i]+1;
}
if(prev<=r)
ans+=compute(a,prev,r,minval);
return min(ans,r-l+1);
}

int a[50005];
int main()
{
int n;
scanf("%d",&n);

for(int i =1;i<=n;i++)
scanf("%d",&a[i]);

cout<<compute(a,1,n,0)<<endl;
  return 0;
}
