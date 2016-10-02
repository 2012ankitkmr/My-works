#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{ ll a,n,d,a3,a3n,Sn;
int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld%lld%lld",&a3,&a3n,&Sn);
		
		n=(2*Sn)/(a3+a3n);
		d=(a3n-a3)/(n-5);
		a=a3-(2*d);
		printf("%lld\n",n);
		for(ll i=a,j=n;j--;i+=d)
		printf("%lld ",i);
		printf("\n");
	}
	
}
