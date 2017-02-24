#include<bits/stdc++.h>
using namespace std;

int sieve[1000006];
int main()
{
	int i = 2;
	while(i<=1000000)
	{
		if(!sieve[i])
		{
			int j =2,num;
			while((num = i*j)<=1000000)
			{
				sieve[num]=1;
				j++;
			}
			
		}
		i++;
	}
	int n;
	cin>>n;
	for(int i = 1;i<=(n/2);i++)
	{
		if(sieve[i]&&sieve[n-i])
		{
		printf("%d %d\n",i,n-i);
		break;	
		}
	}
	
	
	return 0;
}
