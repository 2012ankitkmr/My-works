#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1003];
int n;

ll dp[1003];

int main()
{
	scanf("%d",&n);
	for(int i = 1; i<=n;i++)
	scanf("%d",&a[i]);
	

for(int i =1;i<=n+1;i++)
dp[i]=(2*dp[i-1]+2 - dp[a[i-1]]+1000000007)%1000000007;	
	cout<<(dp[n+1]-2)%1000000007;
	return 0;
}
