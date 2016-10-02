#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
if(k==0)
{
	for(int i =1;i<=2*n;i++)
	printf("%d ",i);
	return 0;
}

	for(int i = 1 ; i<=2*k;i+=2)
	{
		printf("%d %d ",i+1,i);
	}
	for(int i = 2*k+1 ; i<=2*n;i+=2)
	{
		printf("%d %d ",i,i+1);
	}
	return 0;
}
