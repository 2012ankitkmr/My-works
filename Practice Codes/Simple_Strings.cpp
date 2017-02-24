#include "bits/stdc++.h"
using namespace std;
int n,k;
char s[200005];
int dp[200005][28];


int main()
{
  k=2;
scanf("%s",s);
n = strlen(s);
for(int i = 0 ;i<200002;i++)
{
  for(int j = 0;j<26;j++)
  {
    dp[i][j]=INT_MAX;
  }
}

dp[0][0]=1;
dp[0][1]=1;
dp[0][s[0]-'a']=0;
int prev = s[0]-'a';
for(int i = 1;i<n;i++)
{

for(int k = 0;k<26;k++)
{
for(int j = 0;j<26;j++)
{
  if(j!=k)
  dp[i][k] = min(dp[i][k],dp[i-1][j]);
}
dp[i][k]+=(s[i]!=('a'+k));
}
prev = s[i]-'a';
}

int mn=INT_MAX,ind;
for(int i = 25;i>=0;i--)
if(mn>dp[n-1][i])
{
  mn = dp[n-1][i];
  ind=i;
}
s[n-1]= 'a'+ind;
prev = ind;
for(int j = n-2;j>=0;j--)
{
  mn = INT_MAX;
  for(int i = 25;i>=0;i--)
  {
    if(i!=prev)
    if(mn>dp[j][i])
  {
    mn = dp[j][i];
    ind=i;
  }
}
//printf("%d\n",ind);
  s[j]=ind+'a';
  prev = ind;
}



cout<<s<<endl;
  return 0;
}
