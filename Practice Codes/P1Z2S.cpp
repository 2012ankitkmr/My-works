#include<bits/stdc++.h>
using namespace std;


int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++ )
	scanf("%d",&a[i]);
	
	int odd = 0 , ans = 0 , tickets = 0 ,one = 0 ,takers = 0;
	for(int i = 0; i < n ; i++ )
	{
		tickets+=((a[i]+1)/2);
		if(a[i] == 1)
		one++;
		else {
		takers+=(a[i]-2);
	}
	}
	if(takers>one)
	ans = n + (takers-one+1)/2;
	else
	ans = n;
	printf("%d\n",ans);
	return 0;
}
