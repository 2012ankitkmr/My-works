#include<bits/stdc++.h>
using namespace std;

long long  gcd(long long a ,long long b)
{
	if(b == 0)
	return a;
	else
	return gcd(b,a%b);
}

long long max(long long a,long long b)
{
	return a>b?a:b;
}

bool sieve[1000006];
int main()
{
	long long  n;
	
	cin>>n;
	if(n==1||n==2)
	printf("%d\n",n);
    else if(n&1)
	{
		long long ans = n*(n-1)*(n-2);
		cout<<ans;
	}
	else if (n==4)
	cout<<12;
	else if (n==6)
	cout<<60;
	else
	{
		
		int i = 2 ,m = ceil(sqrt(n)) ;

		while(i<=m)
		{
			if(!sieve[i])
			{
				int j = 2 , num;
				while((num = i*j)<=n)
				{
					sieve[num] = 1;
					j++;
				}
			}
			
			i++;
		}
	
	long long a = n*(n-1),b,k = n;
	for(long long  i = n - 2; i >= 0 ; i-- )
	{
		if(!sieve[i])
		{
		//	printf("%d\n",i);
			b = i;
			break;
		}
		if(gcd(a,i)==1)
		{
			b = i;
			break;
		}	
	}
	cout<<max(a*b,(k-1)*(k-2)*(k-3));
	
	}
	return 0;
}
