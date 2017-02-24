#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	cout<<(n/2)<<"\n";
	for(int i = 1;i<=(n/2)-1;i++)
	printf("%d ",2);
	if(n&1)
	printf("3");
	else
	printf("2");
	return 0;
}
