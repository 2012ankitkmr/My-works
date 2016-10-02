#include<bits/stdc++.h>

using namespace std;
bool sum[1000000];
int main()
{
	int n,a[111],tempsum,totsumm;
	while(1)
	{
		memset(sum,0,sizeof sum);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	
		a[i]=i;
	}
	
	do{
		for(int i=1;i<=n;i++)
		{
			tempsum=0;
			for(int j=1;j<=i;j++)
			{
				tempsum+=a[j];
			}
			//printf("in looop %d\n",tempsum);
			sum[tempsum]=1;
		}
		
	}while(next_permutation(a,a+n+1));
	totsumm=n*(n+1);
	totsumm>>=1;
	
	for(int i=1;i<=totsumm;i++)
	{
		if(sum[i])
		printf("%d\n",i);		
		
	}
	
}
	
}
