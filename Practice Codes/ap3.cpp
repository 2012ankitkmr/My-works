#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{ ll a,n,d,a3,a3n,Sn,sum,diff,b;
int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld%lld%lld",&a3,&a3n,&Sn);
	sum=a3+a3n;
	diff=a3n-a3;
		b=(6*sum+2*Sn-diff);
		//printf("%lld",b);
		n=b+(ll)sqrt(b*b-4*sum*12*Sn);
	
		n/=(2*sum);
	
		d=(2*Sn)/n-sum;
/*	if(d<0)
	{
			n=b-(ll)sqrt(b*b-4*sum*12*Sn);
		n/=(2*sum);		
		d=2*Sn/n-sum;
	}*/
		printf("n=%lld,d=%lld\n",n,d);
		a=a3-(2*d);
		printf("%lld\n",n);
		for(ll i=a,j=n;j--;i+=d)
		printf("%lld ",i);
		printf("\n");
	}
	
}
