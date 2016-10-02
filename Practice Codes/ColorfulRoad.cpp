#include<bits/stdc++.h>
using namespace std;

class ColorfulRoad
{
	public:
	int getMin(string road)
	{
	int len=road.length();
	int cost[22];
	map<char,int>mymap;
	mymap['R']=0;
	mymap['G']=1;
	mymap['B']=2;
	char set[]="RGB";
for(int i=0;i<=18;i++)
cost[i]=2000000;
	queue<int>q;
	q.push(0);
	cost[0]=0;
	int color=0;
	//printf("cost=%d \n",cost[len-1]);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		color=mymap[road[p]];
		for(int i=p+1;i<len;i++)
		{
			if(road[i]==set[(color+1)%3])
			{
	//		printf("road=%c,set=%c,p=%d,i=%d\n",road[i],set[(color+1)%3],p,i);
			q.push(i);
			cost[i]=min(cost[i],cost[p]+(i-p)*(i-p));
		    }
		}	
	}
	
	//printf("cost=%d \n",cost[len-1]);
	if(cost[len-1]==2000000)
	return -1;
	else
	return cost[len-1];	
		
	}
	
	
};

int main()
{
	ColorfulRoad ank;
	string s="RGGGB";
	printf("%d\n",ank.getMin(s));
	return 0;
}
