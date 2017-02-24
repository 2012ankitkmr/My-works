#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,mid,k;
	cin>>n>>k;
	mid = (n+1)>>1;
		if(k<=mid)
		printf("%lld\n",1+(k-1)*2);
		else
		printf("%lld\n",2+(k-mid-1)*2);
		
	
	
	
	return 0;
}
