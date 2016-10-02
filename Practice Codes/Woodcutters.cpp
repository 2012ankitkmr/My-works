#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[100005],h[100005],leftoccupied,cnt;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++)
	scanf("%d%d",&a[i],&h[i]);
	
	a[n]=INT_MAX,h[n]=0;
	leftoccupied = INT_MIN;
	cnt = 0 ;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(leftoccupied < ( a[i] - h[i]))
		{
			leftoccupied = a[i];
			cnt++;
		}
		else if(a[i+1] > (a[i] + h[i]))
		{
			cnt++;
			leftoccupied = a[i] + h[i];
		}
		else
		{
			leftoccupied=a[i];
		}
		
	}
	printf("%d\n",cnt);
	return  0;
}
