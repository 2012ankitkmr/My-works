#include<bits/stdc++.h>
using namespace std;


int a[100001];
int main()
{
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	
	sort(a,a+n);
	int cnt= 0;
	for(int i = 0;i<n;i++)
	{
		k-=a[i];
		
		if(k<0)
		break;
		
		cnt++;
	}
	printf("%d\n",cnt);
	return  0;
}
