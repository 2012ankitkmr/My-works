#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b,an;
	int t,n;
	char c;
	for(scanf("%d",&t);t--;)
	{
		while(1)
		{
			scanf("%c",&c);
			if(c==' ')
			break;
			n=c-'0';
		}		
		scanf("%lld",&b);
b%=4;
if(b==0)
b=4;
an=1;


 while(b>0)
 {
 	an=an*n;
 	b--;
 }
 an%=10;
		printf("%lld\n",an);
	}
	return 0;
}
