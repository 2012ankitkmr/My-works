#include<bits/stdc++.h>
using namespace std;


double dp[1005][1005];

int main()
{
	freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w+",stdout);
	int n,m,t,l,r;
	double a[1005];
	/*prev=1;
	for(int i=0;i<n;i++)
	{
		ans=1;
		for(int j=0;j<=i;j++)
		{
			ans=a[j]*ans;
		}
		printf("%lf %d\n",ans,i+1);
		ans=pow(ans,(1/(double)(i+1)));
		ans1=pow(prev,((i)/(double)(i+1)));
		ans1=ans1*pow(a[i],(1/(double)(i+1)));
		
		 
		printf("continues=%lf,dp=%lf\n",ans,ans1);
		prev=ans;
	}
	
	*/
	double temp;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		scanf("%lf",&a[i]);
		
		for(int i=0;i<n;i++)
		{
			dp[i][i]=a[i];
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(i<j)
				{
					temp=pow(dp[i][j-1],(j-i)/(double)(j-i+1));
					temp=temp*pow(a[j],1/(double)(j-i+1));
					dp[i][j]=temp;					
				}			
			}			
		}
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%.9lf ",dp[i][j]);
			}
			printf("\n");
		}
	
	*/
	printf("Case #%d:\n",test);
		while(m--)
		{
			scanf("%d%d",&l,&r);
			printf("%.9lf\n",dp[l][r]);			
		}
		
	}
	return 0;
}
