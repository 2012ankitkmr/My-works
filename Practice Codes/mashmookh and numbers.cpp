#include<bits/stdc++.h>
using namespace std;


bool sieve[8000006];
int main()
{
	int i=2;
while(i<=3000)
{
	if(!sieve[i])
	{
		int j=2,num;
		while((num=i*j)<=8000006)
     	{
		sieve[num]=1;
		j++;
	    }
		
	}
	i++;
}
vector<int>primes;
primes.push_back(1);
for(i=2;i<=8000006;i++)
{
	if(!sieve[i])
	{
		primes.push_back(i);
	}
}
	
	
	int n,k;
	scanf("%d%d",&n,&k);
	if(k<(n/2)||(n==1&&k))
	{
		printf("-1\n");
	}
	else if(k==(n/2))
	{

		for(i=0;i<n;i++)
		{
			printf("%d ",primes[i]);
		}
	}
	else
	{
		k=k-(n/2)+1;
		printf("%d %d ",k,2*k);
		if(k>8000006)
		{
		for(i=0;i<n-2;i++)
		{
			printf("%d ",primes[i]);
		}
	   }
	   else
	   {
	   		int flag=0;
	   	for(i=0;i<n-2;i++)
		{
			if(primes[i]==k)
			{
				flag=1;
			}
			else
			printf("%d ",primes[i]);
		}	
	   	if(flag)
	   	{
	   		printf("%d",primes[n-2]);
	   	}
	   }
	}
	return 0;
}
