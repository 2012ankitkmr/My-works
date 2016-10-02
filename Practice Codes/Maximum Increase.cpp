#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[100005];
	scanf("%d",&n);
	
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	
	int cnt = 1 ,maxcnt = 1;
	for(int i = 1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}
		maxcnt = max(maxcnt,cnt);
	}
	printf("%d\n",maxcnt);
	
	return 0;
}
