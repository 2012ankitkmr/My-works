#include<stdio.h>
#include<string.h>
int agnes[2005];
int tom[2005];
int dp[2001][2001];
int max(int a,int b)
{
	return a>b?a:b;
}
int lcs(int m,int n)
{
if(m==0||n==0)
return 0;
if(dp[m][n]!=-1)
return dp[m][n];

else if(agnes[m-1]==tom[n-1])
 dp[m][n]=1+lcs(m-1,n-1);
else
 dp[m][n]=max(lcs(m-1,n),lcs(m,n-1));

return dp[m][n];
}

int main()
{
	
	int t,temp,i,len2,len1,res,max;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&temp);
		i=0;
		max=0;
		while(temp!=0)
		{
			agnes[i++]=temp;
			scanf("%d",&temp);
		}
		len1=i;
		scanf("%d",&temp);
		while(temp!=0)
		{
		i=0;
		while(temp!=0)
		{
			tom[i++]=temp;
			scanf("%d",&temp);
		}
		len2=i;
		memset(dp,-1,sizeof dp);
		res=lcs(len1,len2);
		if(max<res)
		max=res;
	//	printf("len1=%d,len2=%d\n",len1,len2);
	//	printf("res=%d\n",res);
		scanf("%d",&temp);
       }
		printf("%d\n",max);
	}
	return 0;
}
