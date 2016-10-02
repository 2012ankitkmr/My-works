#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,d,n,seed,sum;
	scanf("%d",&test);
	for(int t=0;t<test;t++)
	{
		scanf("%d%d",&d,&n);
		seed=n;
		for(int i=0;i<d;i++)
		{
			sum=(seed)*(seed+1);
			sum>>=1;
			seed=sum;
		}
		printf("%d\n",sum);
		
		
	}
	
	return  0;
}
