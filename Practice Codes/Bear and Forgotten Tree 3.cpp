#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define se second
#define fi first
#define pb push_back
 

vector<pair<int,int> > ans;

int main()
{
	int n,d,h,nodecnt,th,td;
	
	scanf("%d%d%d",&n,&d,&h);
	if(n>2&&d==1&&h==1)
	{
		cout<<"-1";
		return 0;
	}
	
	if(((d<=2*h)&&(d>=h))&&(n>d))
	{
		nodecnt = 1;
		th = h;
		for(int i = 2;i<=n;i++)
		{
			if(th==0)
			break;
			ans.pb(mp(nodecnt++,i));
			th--;
		}
		
		td = d-h;

		if(td)
		{
			td--;
			nodecnt++;
			ans.pb(mp(1,nodecnt));
		}
		for(int j = nodecnt+1;j<=n;j++)
		{
			if(td==0)
			{
			break;
	    	}
			ans.pb(mp(nodecnt++,j));
			td--;
		}
	    
	    if(d==h)
	    {
	    for(int i = nodecnt+1;i<=n;i++)
		ans.pb(mp(2,i));
	    }
	    else
	    {
		for(int i = nodecnt+1;i<=n;i++)
		ans.pb(mp(1,i));
	    }
	    
		for(int i = 0;i<ans.size();i++)
		{printf("%d %d\n",ans[i].fi,ans[i].se);
		}
	}
	else
	printf("-1\n");
	
	return 0;
}
