#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int sum(int n)
{
	return ((n+1)*n)>>1;
	
}

long long fact[303],d,k;
int main()
{
	fact[0]=1;
	int t,n,m;
	for(int i =1;i<=300;i++)
	fact[i]=(i*fact[i-1])%MOD;
	
	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
	if(m<sum(n))
	{
		printf("0\n");
		continue;
	}
	d = (fact[n]*((m-sum(n))>>1))%MOD;
	k=fact[n];
	printf("%d\n",(k+d)%MOD);
		
		
	}
	
	
	return 0;
}
