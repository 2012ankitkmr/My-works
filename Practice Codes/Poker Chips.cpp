#include<bits/stdc++.h>
using namespace std;
#define D 0

int a[55],n;
int getsum(int x)
{
	x = x*(x+1);
	return x>>1;
}

int calculate(int x)
{
	int sum=0;
	for(int i = 0;i<n;i++)
	sum+=abs(a[i]-(x+i));
	return sum>>1;
}
int main()
{

int t,sum,x,ans,sumx;
for(scanf("%d",&t);t--;)
{
	
sum=0;
scanf("%d",&n);
for(int i = 0;i<n;i++)
	{
	scanf("%d",&a[i]);
	sum+=a[i];
}
x = 100;

ans = 9999999;
while(x!=0)
{
	sumx = getsum(x)-getsum(x-n);
	if(sumx==sum)
	{
		if(D)
		printf("first num = %d\n",x-n+1);
	ans = min(ans,calculate(x-n+1));
	x--;
	}
	else
	x--;
}
if(ans==9999999)
printf("-1\n");
else
printf("%d\n",ans);

	
	
}

return  0;
}
