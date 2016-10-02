#include<bits/stdc++.h>
using namespace std;


int t,a,b;
int pd[5000006],pf[5000006];
long long dp[5000006];
int main()
{
pd[1]=1;
int i =2;	
	
	while(i<=(5000000))
	{
	
	if(!pd[i])
	{//printf("here %d\n",i);
		int j = 1,num;
		while((num = i*j)<=5000000)
		{
			num = i*j;
			
			pd[num] = i;
			j++;
		}		
	}
	i++;	
	}
	pf[1]=0;
	for(int j =2;j<=5000000;j++)
	{
	pf[j]=pf[j/pd[j]]+1;

}
	dp[1]=0;
	for(int j =2 ; j <= 5000000 ; j++)
	dp[j]=dp[j-1]+pf[j];

	
	
	for(scanf("%d",&t);t--;)
	{	
	scanf("%d%d",&a,&b);
printf("%I64d\n",dp[a]-dp[b]);
}
	return 0;
}
