#include<bits/stdc++.h>
using namespace std;

bool sieve[1000006];
bool has[1000006];


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
	for(int i = 2;i<=1000000;i++)
	if(!sieve[i])
	has[i] = 1;
	
	int n,cnt;
	cin>>n;
	
	long long t,tt;
	
	for(int i=0;i<n;i++)
	{
		cin>>t;
	
	cnt=0;
	tt = sqrt(t);
	if((tt*tt)==t)
	{
		if(has[tt])
		cnt=1;
	}
	
	
	if(cnt==1)
	printf("YES\n");
	else
	printf("NO\n");
	}
	
	
	return 0;
}
