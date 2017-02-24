#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
//	freopen("in.txt","r+",stdin);
	ll x,y,a,b,logb,loga,plogb,ans=0,ploga;
	
	cin>>x>>y;
	a= x,b=y;
//	int t=0;
	while(1)
	{
		if(a==b)
		break;
//		printf("%lld %lld ",a,b);
	//	system("pause");
		logb = log2(b);
		plogb = 1LL<<logb;
//		printf(" plogb = %lld\n",plogb);
		if(a<plogb)
		{
			ans = plogb|(plogb-1);
			break;
		}
		else
		{
			b = b^plogb;
			loga = log2(a);
		    ploga = 1LL<<loga;
		    a = a^ploga;
		}

	}
	cout<<ans;
	return  0;
}
