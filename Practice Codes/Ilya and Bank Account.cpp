#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,l,s;
	cin>>n;
	if(n<0)
	{
	n= n*(-1);
	l = n%10;
	s = n%100;
	s/=10;
	if(s<l)
		printf("%d\n",(n/10)*(-1));
	else
	printf("%d\n",((n/100)*10+n%10)*(-1));	
    }
    else
    cout<<n;
	
	return 0;
}
