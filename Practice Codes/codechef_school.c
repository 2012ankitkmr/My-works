#include <iostream>
#include <algorithm>
using namespace std;
int ara[300000];
int main()
{
	long long int a,i,x,j;
	scanf("%lld", &a);
	for(i=0;i<a;i++)
		{
		scanf("%lld", &ara[i]);
	}
	x=ara[0]&ara[1];
	for(i=0;i<a;i++)
	{
		for(j=0;j<a-1,j!=i;j++)
		{
			if((ara[i] & ara[j])>x)
				x = ara[i] & ara[j];
		}
	}
	printf("%lld",x);
	return 0;
} 
