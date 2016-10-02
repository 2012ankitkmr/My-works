#include<stdio.h>
char s[100006];
long long int dp[100006];
int main()
{
	long int t,n,k,q,l,r,i,count,j,m,count0,count1;
	
	for(scanf("%ld",&t);t--;)
	{
		scanf("%ld%ld%ld",&n,&k,&q);
		scanf("%s",s);
		
			count=0;
			count0=0;
			count1=0;
			dp[0]=1;
		
			for(j=0;j<n;j++)
			{  	int ank1=0,ank0=0;
				if(s[j]=='0')
				ank0++;
				else
				ank1++;
				
				count0=ank0;
				count1=ank1;
				
				for(m=j+1;m<n;m++)
				{
					if(s[m]=='0')
					count0++;
					else
					count1++;
					
					if((count1<=k)&&(count0<=k))
					dp[j]++;
					else
					break;
					
				}
				
			}
		
		for(i=0;i<q;i++)
		{
			scanf("%ld%ld",&l,&r);
		
			printf("%ld\n",dp[r-1]-dp[l-1]);
			
		}
				
	}
	
	return 0;
}

