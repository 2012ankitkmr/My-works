#include <bits/stdc++.h>
using namespace std;




bool isSorted(int n,int Arr[])
{
  bool flag = 1;
  for(int  i = 1;i<n;i++)
  {
    if(Arr[i]<Arr[i-1])
    flag =0;
  }

return flag;

}

int main()
{
int n,temp;
cin>>n;
int Arr[102];
for(int i = 0;i<n;i++)

{
  cin>>Arr[i];
}

vector<pair<int,int> >lrs;

while(1)
{
//  cout<<"here";
if(isSorted(n,Arr))
break;
for(int i = 1 ;i<n;i++)
{
  if(Arr[i]<Arr[i-1])
  {
    lrs.push_back(make_pair(i,i+1));
    swap(Arr[i],Arr[i-1]);
    i++;
  }
}
}
for(int i = 0 ;i<lrs.size();i++)
printf("%d %d\n",lrs[i].first,lrs[i].second);
  return  0;
}
