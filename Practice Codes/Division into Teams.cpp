#include<bits/stdc++.h>
using namespace std;

struct player{
	int strength;
	int ind;
};

bool comp(const player x,const player y)
{
	return x.strength<y.strength;
}

int n;
player a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].strength);
		a[i].ind=i+1;	
	}
	sort(a,a+n,comp);
	printf("%d\n",(n+1)/2);
	for(int i=0;i<n;i+=2)
	{
		printf("%d ",a[i].ind);
	}
	printf("\n");
	printf("%d\n",n/2);
	for(int i=1;i<n;i+=2)
	{
		printf("%d ",a[i].ind);	
	}
	printf("\n");
	
	return 0;
}
