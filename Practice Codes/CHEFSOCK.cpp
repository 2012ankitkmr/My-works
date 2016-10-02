#include<bits/stdc++.h>
using namespace std;

int main()
{
	int j,s,m;
	cin>>j>>s>>m;
	m-=j;
	m/=s;
	if(m%2==0)
	printf("Lucky Chef\n");
	else
	printf("Unlucky Chef\n");
	return  0;
}
