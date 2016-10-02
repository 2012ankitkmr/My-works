#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int main()
{
	int n,q,a,b,temp;
	scanf("%d%d",&n,&q);
	a=INT_MAX;
	b=INT_MIN;
	for( int i = 0; i < n ; i++ )
	{
		scanf("%d",&arr[i]);
	a= min(arr[i],a);
	b= max(arr[i],b);	
	}
//	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&temp);
		if(temp>=a&&temp<=b)
		{
			printf("Yes\n");
		}
		else
		printf("No\n");
	}
	return 0;
}
