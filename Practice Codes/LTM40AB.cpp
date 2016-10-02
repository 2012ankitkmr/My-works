#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll a,b,c,d,m,cnt,ans;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		
		m= max(d,a)-max(c,a)+1;
		cnt =0;
		ans =0;
		if(a>=d)
		m=0;
		for(int i = a;i<=b;i++)
		{
			if(i>=c&&i<=d)
			cnt++;
			
			ans += (m-cnt);
				
		}
		printf("%lld\n",ans);
		
	}
	
	
	return 0;
}
