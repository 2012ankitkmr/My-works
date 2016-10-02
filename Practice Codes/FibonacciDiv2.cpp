#include<bits/stdc++.h>
using namespace std;
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"

class FibonacciDiv2{
public:
	int find(int n)
	{
long int ans=0;
	gl(i,0,33)
	{
		if(fib[i]==n)
	break;
		if(fib[i]>n)
		{
			ans=min(abs(n-fib[i-1]),abs(n-fib[i]));
			break;
		}
	}
	return ans;
	}
};


