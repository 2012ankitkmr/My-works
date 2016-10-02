#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long 

pair<int ,int >cabs[1003];

int main()
{
	int t,n,m,a,b,bestcab,sx,dx,sy,dy;
     long double min_dis,dis;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)
	{
	scanf("%d%d",&a,&b);
	cabs[i].fi =a;
	cabs[i].se =b;
    }
    for(int i = 1;i<=m;i++)
	{
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&dx,&dy);
	
	    min_dis=9999999999999999999.0;
    	for(int j = 1;j<=n;j++ )
    	{
    		dis=(pow((cabs[j].first-sx),2)+pow((cabs[j].second-sy),2));
    		if(dis<min_dis)
    		{
    			min_dis =dis;
    			bestcab = j;
    		}
    	}
    	
        printf("%d\n",bestcab);
    	cabs[bestcab].fi = dx;
    	cabs[bestcab].second = dy;
    }    
	}
	return 0;
}
