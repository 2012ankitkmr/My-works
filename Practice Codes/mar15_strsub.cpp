#include<stdio.h>
char s[100006];
int dp[100006][100006];
int main()
{
	long int p,t,n,k,q,l,r,i,j,m,count0,count1;
	
	for(scanf("%ld",&t);t--;)
	{
		scanf("%ld%ld%ld",&n,&k,&q);
		scanf("%s",s);
		p=1;
			
			for(j=0;j<n;j++)
			{  	dp[j][0]++;
			count0=0;
			count1=0;	
			while(p<=n)
			{
				for(m=j;m<p;m++)
				{
					if(s[m]=='0')
					count0++;
					else
					count1++;
					
					if((count1<=k)&&(count0<=k))
					dp[j][p]++;
					else
					break;
				}
			p++;
			}
				printf("dp[%d][%d]=%d\n",j,p,dp[j][p]);
			}
		
		
		for(i=0;i<q;i++)
		{
			scanf("%ld%ld",&l,&r);
		
			printf("%ld\n",dp[l-1][r-1]);
			
		}
				
	}
	
	return 0;
}

