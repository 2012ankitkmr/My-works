#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll max(ll a,ll b)
{
	return a>b?a:b;
}

ll min(ll a,ll b)
{
	return a<b?a:b;
}

struct mypair{
	ll fi,se;
}inv[500005];

bool comp(const struct mypair a,const struct mypair b)
{
	if(a.fi==b.fi)
	{
		return a.se<b.se;
	}
	else
	return a.fi<b.fi;
	
}

ll getcurinv(struct mypair pp)
{
	return (pp.se-pp.fi+1);
}

ll findtotlen(struct mypair a[],ll n)
{
	ll len = getcurinv(a[1]),diff,rightmax = a[1].se;
	
	//		printf("%lld %lld,len = %lld\n",inv[1].fi,inv[1].se,len);
	for(int i =2; i<=n ; i++)
	{
			if(a[i].fi > rightmax)
		{
			len += getcurinv(a[i]);
		}
		else
		{
			diff = a[i].se - rightmax;
			if(diff > 0)
			len += diff;
			
	//		printf("here ");
		}
		rightmax = max(rightmax,a[i].se);
//	if(i<=50)
//			printf("%lld %lld,len = %lld\n",inv[i].fi,inv[i].se,len);
	}
	
	return len;
}



ll x[500005],y[500005];

int main()
{
	
	freopen("C-small-attempt1.in","r+",stdin);
//	freopen("out.txt","w+",stdout);
	int t;
	
	ll l1,r1,A,B,C1,C2,M,n,temp1,temp2,netlength,toberemoved,cur_rem;
	scanf("%d",&t);
	for(int test = 1;test<=t;test++)
	{

scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&l1,&r1,&A,&B,&C1,&C2,&M);

inv[1].fi = l1,inv[1].se = r1;
x[1] = l1,y[1] = r1;
for(int i = 2; i <= n; i++)
{
	x[i] = (A*x[i-1] + B*y[i-1] + C1)%M;
	y[i] = (A*y[i-1] + B*x[i-1] + C2)%M; 
 
	inv[i].fi = min(x[i],y[i]);
	inv[i].se = max(x[i],y[i]);

}


sort(inv+1,inv+n+1,comp);


netlength = findtotlen(inv,n);
toberemoved = -1;
//printf("len = %lld\n",netlength);
inv[0].se = -1;
inv[n+1].fi = 1000000000000;

ll maxright= -1;
for(int i = 1 ; i<=n ; i++)
{
	
	if(inv[i].fi>maxright&&inv[i].se<inv[i+1].fi)
	{
		cur_rem = getcurinv(inv[i]);
	}
	else if (inv[i].fi>maxright&&inv[i].se>=inv[i+1].fi)
	{
		if(inv[i+1].fi<=inv[i].se&&inv[i].se<=inv[i+1].se)
		{
			cur_rem = getcurinv(inv[i])-(inv[i].se - inv[i+1].fi+1);
		}
		else
		{
			cur_rem = getcurinv(inv[i])-getcurinv(inv[i+1]);
		}
		
	}
	else if(inv[i].fi <= maxright && inv[i].se < inv[i+1].fi)
	{
		cur_rem = getcurinv(inv[i]) - (maxright - inv[i].fi +1);
		if(cur_rem<0)
		cur_rem = 0;
	}
	else if(inv[i].fi <= maxright && inv[i].se >= inv[i+1].fi)
	{
		cur_rem = getcurinv(inv[i]) - (maxright - inv[i].fi +1);
		
		if(cur_rem<0)
		{
			cur_rem = 0;			
		}
		else
		{
		if(maxright<inv[i+1].fi)
		{
		
		if(inv[i+1].fi<=inv[i].se&&inv[i].se<=inv[i+1].se)
		{
			cur_rem = cur_rem - (inv[i].se - inv[i+1].fi+1);
		}
		else
		{
			cur_rem = cur_rem - getcurinv(inv[i+1]);
		}
	
		if(cur_rem<0)
		cur_rem  = 0;
	}
	else
	{
		if()
		
	}
	}
	}
	
	toberemoved = max(toberemoved,cur_rem);
}

printf("Case #%d: %lld\n",test,netlength-toberemoved);
	
	}
	
	return  0;
}
