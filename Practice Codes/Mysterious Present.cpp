#include<bits/stdc++.h>
using namespace std;

struct evl{
	int he,wi,ind;
}a[5003];

bool comp(const evl&a,const evl&b)
{
	if(a.wi==b.wi)
	return a.he<b.he;
	else
	return a.wi<b.wi;
}
int n,w,h;

void find_lis(vector<evl> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (int i = 1; i < a.size(); i++) 
        {
 
		if (a[b.back()].he < a[i].he) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]].he < a[i].he) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i].he < a[b[u]].he) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
int main()
{
	//freopen("in.txt","r+",stdin);
	scanf("%d%d%d",&n,&w,&h);
	
	for(int i =0;i<n;i++)
	{
		scanf("%d%d",&a[i].wi,&a[i].he);	
		a[i].ind= i+1;
	}
	sort(a,a+n,comp);
	
	vector<evl>ans;
	map<int,int>mymap1,mymap2;
	for(int i =0;i<n;i++)
	{
//	printf("%d %d %d\n",a[i].wi,a[i].he,a[i].ind);
		if(a[i].wi<=w)
		continue;
		if(a[i].he<=h)
		continue;	
		if(mymap1[a[i].wi]==0&&mymap2[a[i].he]==0)
	{
		ans.push_back(a[i]);
		mymap1[a[i].wi]=1;
		mymap2[a[i].he]=1;
	}
		
	}
//printf("%d\n",ans.size());
vector<int> lis;  	
	find_lis(ans,lis);
	printf("%d\n",lis.size());
	for (int i = 0; i < lis.size(); i++)
		printf("%d ", ans[lis[i]].ind);
        printf("\n");    
 
	return 0;
}
