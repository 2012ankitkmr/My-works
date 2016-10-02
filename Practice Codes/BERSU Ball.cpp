#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++ )
	scanf("%d",&a[i]);
	
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++ )
	scanf("%d",&b[i]);
	
	sort(a,a+n);
	sort(b,b+m);
	//memset(used,0,sizeof used);
	int secondpointer = 0 , ans = 0 ;
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = secondpointer ; j < m ; j++ )
		{
			if(b[j]>a[i]+1)
			break;
			
			if(abs(a[i]-b[j])<=1)
			{
				ans++;
				secondpointer = j + 1;
				break;
			}
			
		}
		
	}
	printf("%d\n",ans);
	
	return 0;
}
