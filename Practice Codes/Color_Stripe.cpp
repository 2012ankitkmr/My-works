#include "bits/stdc++.h"
using namespace std;
int n,k;
char s[500005];
int dp[500005][28];


int main()
{
  scanf("%d%d",&n,&k);
scanf("%s",s);
for(int i = 0 ;i<500002;i++)
{
  for(int j = 0;j<26;j++)
  {
    dp[i][j]=INT_MAX;
  }
}

dp[0][0]=1;
dp[0][1]=1;
dp[0][s[0]-'A']=0;
int prev = s[0]-'A';
for(int i = 1;i<n;i++)
{

for(int l = 0;l<k;l++)
{
for(int j = 0;j<k;j++)
{
  if(j!=l)
  dp[i][l] = min(dp[i][l],dp[i-1][j]);
}
dp[i][l]+=(s[i]!=('A'+l));
}
prev = s[i]-'A';
}

int mn=INT_MAX,ind;
for(int i = k-1;i>=0;i--)
if(mn>dp[n-1][i])
{
  mn = dp[n-1][i];
  ind=i;
}
printf("%d\n",mn);
s[n-1]= 'A'+ind;
prev = ind;
for(int j = n-2;j>=0;j--)
{
  mn = INT_MAX;
  for(int i = k-1;i>=0;i--)
  {
    if(i!=prev)
    if(mn>dp[j][i])
  {
    mn = dp[j][i];
    ind=i;
  }
}
//printf("%d\n",ind);
  s[j]=ind+'A';
  prev = ind;
}



cout<<s<<endl;
  return 0;
}
