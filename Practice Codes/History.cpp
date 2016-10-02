#include<bits/stdc++.h>
using namespace std;

struct history
{
int st,en;	
};

bool comp(struct history a,struct history b)
{
	return a.st<b.st;
}

int main()
{
	history year[100005];
	int n,cnt=0,maxright,minleft;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d",&year[i].st,&year[i].en);
	sort(year,year+n,comp);
	minleft=year[0].st,maxright=year[0].en;
	for(int i=1;i<n;i++)
	{
		if(maxright<year[i].en)
		{
			minleft=year[i].st;
			maxright=year[i].en;
		}
		if(minleft<year[i].st&&maxright>year[i].en)
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
