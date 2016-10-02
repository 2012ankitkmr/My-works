#include<bits/stdc++.h>
using namespace  std;

int n , a[100005] , k , sum , total,ans;
int main()
{
	scanf("%d", &n );
	for(int i = 0 ; i < n ; i++ )
	{
	scanf("%d", &a[i] );
	total += a[i];
    }
	if(total&1)
	{
		printf("0\n");
	}
	else
	{
	k = total>>1;
	sum=0;
	
	for(int i = 0 ; i < n ; i++ )
	{
		sum+=a[i];
		
		if(sum==k)
		ans++;
		if(sum==total&&i==n-1)
		ans++;	
	}
	printf("%d\n",ans-1);
	}
	
	return 0;
}
