#include<bits/stdc++.h>
using namespace std;

int n,m,a,b,has[1003];

int main()
{	
scanf("%d%d",&n,&m);
for(int i = 0;i<m;i++)
{
	scanf("%d%d",&a,&b);
	has[a]=1;
	has[b]=1;
}
int pivot = -1;

for(int i = 1;i<=n;i++)
{
	if(!has[i])
	{
		pivot= i;
		break;
	}
}
	
	printf("%d\n",n-1);
	for(int i =1;i<= n;i++)
	{
		if(pivot==i)
		continue;
		
		printf("%d %d\n",i,pivot);
		
	}
	
	return  0;
}
