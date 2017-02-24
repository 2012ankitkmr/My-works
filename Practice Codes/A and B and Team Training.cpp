#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int n,m;
	cin>>n>>m;
	if(m<n)
	swap(n,m);
	
	if(m>2*n)
	printf("%d\n",n);
	else
	printf("%d\n",(n+m)/3);
	
	return 0;
	
}
