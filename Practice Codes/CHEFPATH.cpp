#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long test,n,m;
	for(scanf("%lld",&test);test--;)
	{
		scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		if(m==2)
		printf("Yes\n");
		else
		printf("No\n");
	}
		else if(m==1)
	{
		if(n==2)
		printf("Yes\n");
		else
		printf("No\n");
	}
	
		else{
			
			if((n&1)&&(m&1))
			printf("No\n");
			else
			printf("Yes\n");
		}
	}
	return 0;
}
