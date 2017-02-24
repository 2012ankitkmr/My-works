#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
vector<pair<int ,int> >vec;

struct order{
	int c,p,in;
}ord[1003];
int n,k,a[1003];
bool comp(struct order a,struct order b)
{
	return a.p>b.p;
}
bool comp2(pair<int,int>a,pair<int,int >b)
{
	if(a.second==b.second)
	return a.first<b.first;
	else
	return a.second<b.second;
}

bool has[1003];
int main()
{
//	freopen("in.txt","r+",stdin);
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
	scanf("%d%d",&ord[i].c,&ord[i].p);
	ord[i].in = i+1;
}
	scanf("%d",&k);
	for(int i = 0 ;i<k;i++)
	{
	scanf("%d",&a[i]);
	has[i]=1;
   } 
	sort(ord,ord+n,comp);
	
	int ans = 0,minval=INT_MAX,ind;
	for(int i =0;i<n;i++)
	{
		minval = INT_MAX;
		for(int j =0;j<k;j++)
		{
			if(has[j])
			{
				if((minval>a[j])&&(ord[i].c<=a[j]))
				{
					minval = a[j];
					ind = j;
				}
				
			}
			
		}
		if(minval!=INT_MAX)
		{
			has[ind]=0;
			ans+=ord[i].p;
			vec.pb(mp(ord[i].in,ind+1));
		}
	}
	cout<<vec.size()<<" "<<ans<<endl;
	sort(vec.begin(),vec.end(),comp2);
	for(int i = 0;i<vec.size();i++)
	{
		printf("%d %d\n",vec[i].first,vec[i].second);
	}
	
	return 0;
}
