#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a[100005];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long int sum=0;
	for(int i=0;i<n;i++)
	sum+=a[i];
	long long ans=ceil((sum/(double)(n-1)));
	for(int i=0;i<n;i++)
	ans=max(ans,a[i]);
	cout<<ans;
	
	return 0;
}
