#include<bits/stdc++.h>
using namespace std;

	int ax,ay,bx,by,tx,ty;
	int n;
	double x[100005],y[100005],sum,cost[100005];
		
	double dis(int in,int a,int b)
	{
		return sqrt(pow(x[in]-a,2)+pow(y[in]-b,2));
	}	

int main()
{
	//freopen("in.txt","r+",stdin);
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	scanf("%lf%lf",&x[i],&y[i]);
	sum=0;
	for(int i = 0;i<n;i++)
	{
	cost[i] = 2*dis(i,tx,ty);
	sum+=cost[i];
//	cout<<cost[i]<<endl;
    }
//printf("sum = %lf\n",sum);
    double minval = 4444444444444444474.444,curcost,K;
    int ind;
	for(int i = 0;i<n;i++)
	{
		curcost = dis(i,ax,ay) + dis(i,tx,ty);
		if((sum-cost[i]+curcost)<minval)
		{
		minval = sum-cost[i]+curcost;
		ind = i;	
		}
	}
	K = sum;
//	printf("%lf,ind = %d\n",minval,ind);
	sum = minval;
	for(int i = 0;i<n;i++)
	{
		if(i==ind)
		continue;
		
		curcost = dis(i,bx,by) + dis(i,tx,ty);
	
		if((sum-cost[i]+curcost)<minval)
		{
		minval = sum-cost[i]+curcost;
		}
	}
	
	    double minval2 = 4444444444444444474.444;
   sum =K;
	for(int i = 0;i<n;i++)
	{
		curcost = dis(i,bx,by) + dis(i,tx,ty);
		if((sum-cost[i]+curcost)<minval2)
		{
		minval2 = sum-cost[i]+curcost;
		ind = i;	
		}
	}
	
	sum = minval2;
	for(int i = 0;i<n;i++)
	{
		if(i==ind)
		continue;
		
		curcost = dis(i,ax,ay) + dis(i,tx,ty);
//		printf("%lf\n",curcost);

		if((sum-cost[i]+curcost)<minval2)
		{
		minval2 = sum-cost[i]+curcost;
		}
	}
printf("%.8lf\n",min(minval,minval2));
	return 0;
} 
