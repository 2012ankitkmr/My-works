#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main()
{
	int n,c;
	
	scanf("%d%d",&n,&c);
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	int cnt = 1;
	for(int i = 1;i<n;i++)
	{
		if((a[i]-a[i-1])<=c)
		cnt++;
		else
		cnt=1;
		
	}
	cout<<cnt;
	return  0;
}
