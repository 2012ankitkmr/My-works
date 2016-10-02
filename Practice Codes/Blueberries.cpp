#include<stdio.h>
#include<string.h>

long int weight[1004];
long int dp[1004][1004];
long int max(long int a,long int b)
{
	return a>b?a:b;
}
int knapsack(int blueberries,int n){
    
    int i,j;
        
    for(i=1;i<=blueberries;i++){
        
        for(j=1;j<=n;j++){
            
            if(i==1){
                if(weight[i-1]<=j)
                     dp[i][j]=weight[i-1];
                
                else dp[i][j]=0;
                
            }
            
            else{
              
              if(j-weight[i-1]<0)
                dp[i][j]=dp[i-1][j];
            
              else dp[i][j]=max(weight[i-1]+dp[i-2][j-weight[i-1]],dp[i-1][j]);        
            
            }
        
        }        
        
    }        
        
    return dp[blueberries][n];
    
}

int main()
{
	long int i,t,n,k;
	for(scanf("%ld",&t);t--;)
	{
	scanf("%ld%ld",&n,&k);
	for(i=0;i<n;i++)	
		scanf("%ld",&weight[i]);

		//memset(dp,0,sizeof(dp));
		printf("%ld\n",knapsack(n,k));
		
	}
	return 0;
	
}
