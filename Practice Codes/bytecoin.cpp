#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;

std::map <long long int ,long long int > M;
map<long long int ,long long int> :: iterator I;
long int W;
long int max(long int a,long int b,long int c,long int d,long int e)
{
	if(a>=b&&a>=c&&a>=d&&a>=e)
	return a;
	else if(b>=a&&b>=c&&b>=d&&b>=e)
	return b;
	else if(c>=a&&c>=b&&c>=d&&c>=e)
	return c;
	else if(d>=b&&d>=c&&a<=d&&d>=e)
	return d;
	else if(e>=b&&e>=c&&e>=d&&a<=e)
	return e;
	
}

long int knapsack(long int n)
{
	
	if(n==0)
	return 0;
	I=M.find(n);
	if(I!=M.end())
	   return I->second;
	   else{
		
		long long int ans=max(W,n/2+n/3+n/4,knapsack(n/2),knapsack(n/3),knapsack(n/4));
		
		
		M.insert(pair<long long int ,long long int>(n,ans));
		return ans;
		
	}
	
}


int main()
{long int n,t;
while(	scanf("%ld",&W)!=EOF)
{


	n=W;
	printf("%ld\n",knapsack(n));
}
	return 0;
	
}
