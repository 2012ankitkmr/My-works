#include<bits/stdc++.h>
using namespace std;

int cnt[100005];
int dp[100005][202],cost[100005],l[1000005],cntcost[100005];
int main()
{
	
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
	scanf("%d",&l[i]);
    cnt[l[i]]++;
    
     }
     for(int i = 0;i<n;i++)
     {
     	scanf("%d",&cost[i]);
     	dp[l[i]][cost[i]]++;
     	cntcost[l[i]]+=cost[i];
     	
     }
     for(int i =1;i<=100000;i++)
     {
     	for(int j = 1;j<=200;j++)
     	{
     		dp[i][j]+=dp[i-1][j];
     	}
     }
   
   int k = n-(n/2),req,co;
   int minval = INT_MAX,overhead=0,cur=n;
   
   for(int i =100000 ;i>=1;i--)
   {
   	if(cnt[i])
   	{
   		
   		co=0;
   		req =cur- (2*cnt[i]-1);
   		
   		for(int j =1;j<=200;j++)
   		{
   			if(req<=0)
   			break;
   			
   			if(req>=dp[i-1][j])
   			{
   				req-=dp[i-1][j];
   				co+=dp[i-1][j]*j;
   			}
   			else
   			{
   				co+=(req*j);
   				req=0;
   			}
   		}
   		minval= min(minval,overhead+co);
   		overhead+=cntcost[i];
   		cur-=cnt[i];
   	}
   }
   printf("%d\n",minval);

	
	return  0;
}
