#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>fib;
int  main()
{
	int n,num;
	
	fib.pb(0);
	fib.pb(1);
	num = 1;
    while(num<1e9)
	{
		num = fib[fib.size() - 1 ] + fib[fib.size() - 2 ];

		fib.pb(num);	
	}
	cin>>n;
	if(n==0)
	printf("0 0 0\n");
	else if(n==1)
	printf("0 0 1\n");
	else if(n==2)
	printf("0 1 1\n");
	else
	{
		int x;
		for(int i = 0;i<fib.size();i++)
		{
			if(n==fib[i])
			{
			x = i;
			break;
		}
		}
		
//		printf("%d\n",x);
	printf("%d %d %d\n",fib[x-4],fib[x-3],fib[x-1]);
    }
	return 0;
}
