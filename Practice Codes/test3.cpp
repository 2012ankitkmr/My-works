#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long int
#define M 1000000007
typedef struct node1
{	ll ank1,ank2,kmr1,kmr2,sum;
	}node;
 

bool haha(const node a,const node b)
{
	if(a.kmr1< b.kmr1) return (a.kmr1<b.kmr1);
	if(a.kmr1> b.kmr1) return (a.kmr1<b.kmr1);
 
	else
	{	if(a.ank1< b.ank1) return (a.ank1<b.ank1);
	if(a.ank1> b.ank1) return (a.ank1<b.ank1);
 
		else
		{
			if(a.ank2< b.ank2) return (a.ank2< b.ank2);
			if(a.ank2> b.ank2) return (a.ank2< b.ank2);
			else
				{
				if(a.kmr2< b.kmr2) return (a.kmr2< b.kmr2);
				if(a.kmr2> b.kmr2) return (a.kmr2< b.kmr2);
				}
		}
	}
}
 
int main() {
	node1 nod[100000];
	ll n,s,i,t,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(i=0;i<k;i++)
	{	scanf("%lld%lld%lld%lld",&nod[i].ank1,&nod[i].ank2,&nod[i].kmr1,&nod[i].kmr2);
	nod[i].sum=0;
	}
	sort(nod,nod+k,haha);

	map<pair<ll,ll>,ll>val;
	ll ui,c,d,ankit;
	c=d=0;
	while(nod[c].ank1==0)
	{
		nod[c].sum=1;
		c++;
	}
	ankit=1;
	for(i=1;i<=n;i++)
	{	ui=0;
		while(nod[d].kmr1==i)
		{	ll y=nod[d].kmr2;
			while(nod[d].kmr2==y && nod[d].kmr1==i)
			{
					val[make_pair(i,y)]=(val[make_pair(i,y)]+nod[d].sum)%M;
				ui=(ui+nod[d].sum)%M;
				d++;
			}
		
		}
		while(nod[c].ank1==i)
		{	
			if(val[make_pair( nod[c].ank1 ,nod[c].ank2 )] !=0)
			nod[c].sum=val[make_pair( nod[c].ank1 ,nod[c].ank2 )];
			nod[c].sum=(nod[c].sum+ankit)%M;
			c++;
		}
		ankit= (m*ankit)%M;
		ankit = (ui+ankit)%M;
		
 
	}
	ui=0;
	while(nod[d].kmr1==n+1)
		{	
 
			ll y=nod[d].kmr2;
			while(nod[d].kmr2==y && nod[d].kmr1==i)
			{	
				val[make_pair(i,y)]=(val[make_pair(i,y)]+nod[d].sum)%M;
				ui=(ui+nod[d].sum)%M;
				d++;
			}
			
		}
 
	ankit=(ankit+ui)%M;
 
	printf("%lld\n",ankit);
	return 0;
}
