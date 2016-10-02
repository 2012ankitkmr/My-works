#include<iostream>
using namespace std;
#define ll long long
#define m 1000000007
 ll po(ll a,ll n)////                              [power]
     {
      	ll x=1,y=a;
	while(n)
	{
		if(n&1)
			x=(x*y)%m;
		y=(y*y)%m;
		n>>=1;
	}
	return x;
}
ll a[1000][1000];
//vector<int>v[1000];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=n;i>0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			a[i][j]=po(m,n-i)+1;
		}
	}
	a[0][0]=m*a[1][0];
	while(k--)
     {
       	int layer1,vertex1,layer2,vertex2;
       	cin>>layer1>>vertex1>>layer2>>vertex2;
       	a[layer1][vertex1]=(a[layer1][vertex1]+a[layer2][vertex2])%m;
       }
       ll sum=a[0][0];
       for(int i=1;i<=n;i++)
       for(int j=0;j<m;j++)
       sum+=a[i][j]%m;
       cout<<sum<<endl;
}
