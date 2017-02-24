#include<bits/stdc++.h>
using namespace std;

int k,l,m,n,d;
int has[100005];
int main()
{
	cin>>k>>l>>m>>n>>d;
	for(int i = 0;i<=d;i+=k)
	{
		has[i]=1;
	}
	for(int i = 0;i<=d;i+=l)
	{
		has[i]=1;
	}
	for(int i = 0;i<=d;i+=m)
	{
		has[i]=1;
	}
	for(int i = 0;i<=d;i+=n)
	{
		has[i]=1;
	}
	
	int cnt=0;
	for(int i = 1;i<=d;i++)
	{
		if(has[i])
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
