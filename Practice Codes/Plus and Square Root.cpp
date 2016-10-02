#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll dp[100005];

int main()
{
	ll n,x,k,p,l;
	cin>>n;
	dp[1]=2;
	
	x=2;
	
	for(int i =2;i<=100000;i++)
	{
		p = i ;
		if(x%i==0)
		{
		k = (p*(i+1)*(i+1)-x/i);			
		}
		else
		{
		k = (p*p*(i+1)*(i+1)-x)/i;
		}dp[i]=k;
		x= (i+1)*p;
//		cout<<dp[i]<<endl;		
	}
for(int i =1;i<=n;i++)
cout<<dp[i]<<endl;	
	
	return 0;
}
