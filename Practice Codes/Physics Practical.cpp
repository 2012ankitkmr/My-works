#include<bits/stdc++.h>
using namespace std;



int c[5003];
int dp[5003];
int a[100005];
int main()
{
int n;
freopen("input.txt","r+",stdin);
freopen("output.txt","w+",stdout);
scanf("%d",&n);

for(int i = 0 ; i < n ; i++)
scanf("%d",&a[i]);

for(int i = 0; i < n ; i++)
c[a[i]]++;
	
for(int i = 1 ; i <= 5000 ; i++)
dp[i]=dp[i-1]+c[i];

int maxv = INT_MIN,l,r,val;

for(int i = 1 ; i <= 2500 ; i++)
{
	l = i;
	r = 2*i;
	val = dp[2*i]-dp[i-1];
	if(val>maxv)
	maxv=val;
}
	
	printf("%d\n",n-maxv);
	return 0;
}
