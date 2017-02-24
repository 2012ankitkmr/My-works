#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair 

vector<pair<int,int> >g[5003];
int n,m,T,a,b,c;

int dp[5003][5003];

/*int compute(int pos,int num,int cost)
{
    if(cost<0)
	return INT_MIN;

	if(pos==n)
	return num;
	
	if(dp[pos][num]!=-1)
	return dp[pos][num];	
	
	int ans = INT_MIN,am,node;
	pair<int,int>to;
	
	for(int i = 0;i<g[pos].size();i++)
	{
		to = g[pos][i];
		node = to.first;
		am = to.second;
		ans = max(ans,compute(node,num+1,cost-am));	
	}
	
	return dp[pos][num]=ans;	
}
*/


int main()
{
	
//freopen("in.txt","r+",stdin);
scanf("%d%d%d",&n,&m,&T);

for(int i = 0;i<m;i++)
{
	scanf("%d%d%d",&a,&b,&c);
	g[a].pb(mp(b,c));
	//g[b].pb(mp(a,c));
}

memset(dp,0,sizeof dp);

//cout<<compute(1,1,T);
int node,am;
pair<int,int>to;
pair<int,pair<int,int> >p;

queue<pair<int,pair<int,int> > >q;
q.push(mp(1,mp(-1,T)));

while(!q.empty())
{
	 p = q.front();
	q.pop();
	
	for(int i = 0;i<g[p.first].size();i++)
	{
		
	//	printf("%d\n",p.first);
	
	    to = g[p.first][i];
		node = to.first;
		am = to.second;
		
		if(am<=p.second.second)
		{
		
		if(p.first!=1)
		dp[p.first][node] = max(dp[p.first][node],dp[(p.second).first][p.first]+1);
		else
		dp[p.first][node] = 1;
		
		if(node!=n)
		q.push(mp(node,mp(p.first,p.second.second-am)));
	    }
		
	}
	//	system("pause");
}
/*
for(int i  =1;i<=n;i++)
{
for(int j = 1;j<=n;j++)
printf("%d ",dp[i][j]);
printf("\n");
}
*/
int ans = INT_MIN,ind;
stack<int>ss;

for(int i = 1;i<=n;i++)
{
	if(ans<dp[i][n])
	{
		ans = dp[i][n];
	}
}	

int maxval;
ss.push(n);
ind = n;

//printf("\n");
int has[5003];
memset(has,0,sizeof has);
has[n]=1;
while(ind!=1)
{
	maxval=INT_MIN;
	node = ind;
	ind=1;
for(int i = 1;i<=n;i++)
{
	if(maxval<dp[i][node])
	{
		maxval = dp[i][node];
		ind = i;
	}
}	
if(!has[ind])
ss.push(ind);
has[ind]=1;

//printf("%d\n",ind);	
}
printf("%d\n",ans+1);
while(!ss.empty())
{
	printf("%d ",ss.top());
	ss.pop();
}
	
	return 0;
}
