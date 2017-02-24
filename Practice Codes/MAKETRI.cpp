#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back

ll n,l,r,a[1000006],rtp,ans;
vector<ll>x,y;

struct node
{
ll x1,y1;	
}xx;
vector<node>nod;

bool comp(struct node a,struct node b)
{
	if(a.x1==b.x1)
	return a.y1<b.y1;
	else
	return a.x1<b.x1;
}
int main()
{
	cin>>n>>l>>r;
	for(ll i = 0 ; i < n ; i++)
	{
		scanf("%lld",&a[i]);		
	}
	sort(a,a+n);
	for(ll i = 1 ; i < n ; i++)
	{
	x.pb( a[i] - a[i-1] + 1);
	y.pb( a[i] + a[i-1] - 1);		
	}
	for(int i = 0 ; i < x.size(); i++ )
	{
		if( l <= y[i] && r >= x[i] )
		{
			xx.x1 = max(l,x[i]);
			xx.y1 = min(r,y[i]);
			nod.pb(xx);
		}
	}
	sort(nod.begin(),nod.end(),comp);
	rtp=0;
	ans=0;
	for(int i = 0 ; i < nod.size() ; i++)
	{
		if(nod[i].x1>rtp)
		{
		ans+=(nod[i].y1-nod[i].x1+1);
		rtp = nod[i].y1;	
		}
		else
		{
		if(nod[i].y1>rtp)
		{
		ans+=(nod[i].y1-rtp);
		rtp = nod[i].y1;	
     	}
		}	
	}
	cout<<ans;
	return 0;
}
