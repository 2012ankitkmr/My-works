#include<bits/stdc++.h>

int main()
{
	unsigned long long int n;
	while(scanf("%llu",&n)!=EOF)
	{
		long long int p;
		p=35184372088832;
		
		if(p%n==0)
		printf("TAK\n");
		else
		printf("NIE\n");
	}
	
	return 0;
}
