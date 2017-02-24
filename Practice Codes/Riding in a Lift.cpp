#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007
int n,a,b,k;

ll dp[5003][5003];
ll sum[5003],ov,temp;

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	if(a<b)
	{
		n=b-1;
	}
	else
	{
		a= b+(n-a)+1;
		n-=b;
		a-=b;
	}
	int len=0;
	for(int i = a+1;i<=n;i++)
	{
	dp[1][i]=1;
len++;
	}
	for(int i = a-1;len--;i--)
	{
		dp[1][i]=1;
	}
	for(int i = 1;i<=n;i++)
	sum[i] = sum[i-1]+dp[1][i];
	for(int i =2;i<=k;i++)
	{

		for(int j = 1;j<=n;j++)
		{
			temp=0;
			if(j!=1)
			{
				temp = sum[j-1]-sum[0]+MOD;
			}
			dp[i][j]+=temp;
			temp=0;
			ov = (n-j)/2;
			ov=ov;
			temp =  sum[j+ov]-sum[j]+MOD;
			dp[i][j]+=temp;
			dp[i][j]=dp[i][j]%MOD;
		}
		for(int j = 1;j<=n;j++)
		sum[j] = (sum[j-1]+dp[i][j])%MOD; 
		
	}
	cout<<sum[n];
	return  0;
}
