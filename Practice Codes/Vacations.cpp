#include<bits/stdc++.h>
using namespace std;



int a[105],n;
int dp[105][4][105];
int compute(int pos,int holiday,int work)
{
	if(pos==n)
	return holiday;
	
	if(dp[pos][work][holiday]!=-1)
	return dp[pos][work][holiday];
	
	int ans = INT_MAX;
	if(a[pos]==0)
	{
		for(int i = 1; i <= n ;i++)
		if( i + pos <= n ) 
		ans = min(ans,compute(i+pos,holiday+1+(i-1),2));
		
	}
	if(a[pos]==1)
	{
		for(int i = 1; i <= n ;i++)
		{
		if(i+pos<=n)
		{
			if(work == 2||work == 1)
   		   ans = min(ans,compute(i+pos,holiday+(i-1),0));
     		
		    ans = min(ans,compute(i+pos,holiday+1+(i-1),2));	   
	    } 
	     }
	}
	if(a[pos]==2)
	{
		for(int i = 1; i <= n ; i++)
		{
		if(i+pos<=n)
		{
			if(work == 2||work == 0)
		    ans = min(ans,compute(i+pos,holiday+(i-1),1));
		    
		    ans = min(ans,compute(i+pos,holiday+1+(i-1),2));	   
	    } 
	     }		
	}
	if(a[pos]==3)
	{
		for(int i = 1; i <= n ;i++)
		{
		if(i+pos<=n)
		{
			if(work == 2||work == 1)
   		    ans = min(ans,compute(i+pos,holiday+(i-1),0));
			
			if(work == 2||work == 0)
		    ans = min(ans,compute(i+pos,holiday+(i-1),1));

		    ans = min(ans,compute(i+pos,holiday+1+(i-1),2));	   
 
	    } 
	     }		
	}
	return dp[pos][work][holiday] = ans;
}
int main()
{
	scanf("%d",&n);
	
	memset(dp,-1,sizeof dp);
	for(int i = 0 ; i < n ; i++ )
	scanf("%d",&a[i]);
	
	printf("%d\n",compute(0,0,2));
	return  0;
}
