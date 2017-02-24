#include<bits/stdc++.h>
using namespace std;

int facts[5000006];
long long sum[5000006];
int main()
{
	int i =2;
	facts[1]=0;
				int j = 1,num,k,cnt;

	while(i<=5000000)
	{
		
		if(!facts[i])
		{
			j=1;
			while((num = (i*j))<=5000000)
			{
				k =num,cnt=0;
				
				while(k%i==0)
				{
					k/=i;
					cnt++;
				}
				
				facts[num]+=cnt;
				
				j++;
			}		
		}
		i++;
	}
	
	for(int i =1;i<=5000000;i++)
	sum[i]=sum[i-1]+facts[i];
	
	
	int t,n,r;
	
	for(scanf("%d",&t);t--;)
	{
	scanf("%d%d",&n,&r);
		printf("%lld\n",sum[n]-sum[n-r]);
		
	}	
	
	return  0;
}
