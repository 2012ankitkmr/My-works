#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ans[5];
	ans[1]=8;
	ans[2]=4;
	ans[3]=2;
	ans[0]=6;
	int n;
	cin>>n;
	if(n==0)
	printf("%d\n",1);
	else
	{
	
	n=n%4;
	printf("%d\n",ans[n]);
	
	}
	
	return 0;
}
