#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,c[102],sum[102],x,y,lsum,rsum;
	memset(sum,0,sizeof sum);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	scanf("%d",&c[i]);
	scanf("%d%d",&x,&y);
	sum[0]=0;
	for(int i=1;i<=m;i++)
	sum[i]=sum[i-1]+c[i];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		lsum=sum[i-1];
		rsum=sum[m]-sum[i-1];
		if((lsum>=x&&lsum<=y)&&(rsum>=x&&rsum<=y))
		{
		ans=i;
	    break;
		}
	}
	print("%d\n",ans);
	
	return 0;
	
}
