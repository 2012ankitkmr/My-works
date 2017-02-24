#include<bits/stdc++.h>
using namespace std;
int a[1000006];
bool win[1000006];
int main()
{
	
	int t,o1,o2,n,k,cnt1,cnt0,cnt,ans;
	for(scanf("%d",&t);t--;)
	{
	scanf("%d%d",&o1,&o2);
	n = o1*o2;
	for(int i =0 ; i<n ; i++)
	scanf("%d",&a[i]);
	cnt1 = 0 , cnt0 = 0 ;

	for(int i = 0 ; i < o2 ; i++)
	{
		if(a[i]==1)
		cnt1++;
		else
		cnt0++;
	}
	for(int i = 0 ; i < n ; i++ )
	win[i]=0;
	for(int i = 0 ; i < n ; i++)
	{
		if(cnt1>cnt0)
			win[i]=1;
			
		if(a[(i+o2)%n]==1)
		cnt1++;
		else
		cnt0++;
		
		if(a[i]==1)
		cnt1--;
		else
		cnt0--;
	}
	k = o1/2;
	ans = 0;
	//printf("array--> ");
	//	for(int i = 0 ; i < n ; i++ )
//	printf("%d ",win[i]);
//printf("\n");
	for(int j = 0 ; j < o2 ; j++)
	{
	cnt=0;
	for(int i = j; i<n ; i+=o2)
	{
		if(win[i]==1)
		cnt++;
	}
	ans = ans|(cnt>k);
    }
    printf("%d\n",ans);
	}
	return 0;
}
