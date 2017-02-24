#include<bits/stdc++.h>
using namespace std;


bool has[102];
int main()
{
	int n,m,x,cntb,cntg,b,g,fl;
	cin>>n>>m;
	int gg = __gcd(n,m);
	cin>>b;
	for(int i = 0;i<b;i++)
	{
		cin>>x;
		has[x%gg]=1;
	}
	cin>>g;
	for(int i = 0;i<g;i++)
	{
		cin>>x;
		has[x%gg]=1;
	}
	fl=0;
	for(int i = 0;i<gg;i++)
	{
		if(!has[i])
		fl=1;
	}
    
    if(fl)
    printf("No\n");
    else
    printf("Yes\n");
	return 0;
}
