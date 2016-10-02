#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test , n ,a[10004] , b[10004] ,prev,cnt ;
	for(scanf("%d",&test);test--;)
	{
		cin>>n;
		for(int i = 0 ;i < n; i++)
		scanf("%d",&a[i]);
		for(int i = 0 ;i < n; i++)
		scanf("%d",&b[i]);
		prev = 0;
		cnt = 0;
		for(int i = 0 ; i < n; i++ )
		{
			if(b[i] <= a[i] - prev)
			{
				cnt++;
			}	
			prev = a[i];
		}
		printf("%d\n",cnt);
	}
	
	return  0;
}
