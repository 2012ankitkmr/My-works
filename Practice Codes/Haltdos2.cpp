#include<bits/stdc++.h>
using namespace std;

int findmax(int n,int arr[])
{
	int min_val = arr[0];
	int ans = -1;
	for(int i = 1;i<n;i++)
	{
		if(arr[i]-min_val>ans)
		ans = arr[i]-min_val;
	}
	return ans;
}

int main()
{
	int n=7;
	int a[]={2,3,10,2,4,8,1};
	printf("%d\n",findmax(a,n));
	return  0;
}
