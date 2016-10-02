#include<bits/stdc++.h>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
 
 
queue<long long> q;
 
long long t,m,k,n,u,v,i,j,l,x,ru,rv;
long long a[200010];
long long b[210];
long long s[210];
long long c[210][200010];
long long mini[210];
 
void inp(long long &x)
{
    register int c = getchar();
    x = 0;
    for(;(c<48 || c>57);c = getchar());
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
long long root(long long z)
{
	while(z!=b[z])
		z=b[z];
	return z;
}
 
int main()
{
	inp(t);
	while(t--)
	{
		inp(m);
		inp(k);
		inp(n);
		for(i=0;i<=m;++i)
		{
			b[i]=i;
			s[i]=1;
		}
 
		while(k--)
		{
			inp(u);
			inp(v);
			ru=root(u);
			rv=root(v);
			if(ru==rv)
				continue;
			else if(s[u]<s[v])
			{
				b[rv]=ru;
				s[ru]+=s[rv];
			}
			else
			{
				b[ru]=rv;
				s[rv]+=s[ru];	
			}
		}
		for(i=0;i<=m;++i)
			b[i]=root(i);
 
		for(i=1;i<=n;++i)
			inp(a[i]);
 
		for(i=0;i<=m;++i)
			c[0][i]=mini[i]=0;
 
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				if(b[j]==b[a[i]])
				{
					if(mini[j]==LLONG_MAX)
						c[j][i]=LLONG_MAX;
					else
						c[j][i]=mini[j]+((j==a[i])?0:1);
				}
				else
					c[j][i]=LLONG_MAX;
			}	
			mini[1]=c[1][i];
			for(j=2;j<=m;++j)
				mini[j]=(c[j][i]<mini[j-1])?c[j][i]:mini[j-1];
		}
 
		if(mini[m]==LLONG_MAX)
			printf("-1\n");
		else
			printf("%lld\n",mini[m]);
	}
	return 0;
}
