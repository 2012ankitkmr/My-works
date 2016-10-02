#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100001];
pair<int,int>pa[100001];
int main()
{
int n,temp,max_val=-1,period,flag;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	scanf("%d",&temp);
vec[temp].push_back(i);
max_val=max(temp,max_val);
}

int cnt=0;
for(int i=1;i<=max_val;i++)
{
	if(vec[i].size()!=0)
	{
		//printf("%d\n",i);
		if(vec[i].size()==1)
		period=0;
		else
		period=vec[i][1]-vec[i][0];
		flag=0;
	for(int j=1;j<vec[i].size();j++)
	{
		if(period!=(vec[i][j]-vec[i][j-1]))
		{
		flag=1;
		break;
     	}
		period=vec[i][j]-vec[i][j-1];
	}	
	if(!flag)
	{	
	pa[cnt].first=i,pa[cnt].second=period;	
	cnt++;
	}			
	}
	
}
printf("%d\n",cnt);
for(int i=0;i<cnt;i++)
{
	printf("%d %d\n",pa[i].first,pa[i].second);
}

return 0;
}
