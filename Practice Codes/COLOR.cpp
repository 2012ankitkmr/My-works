#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,r,g,b;
	char s[100005];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		scanf("%s",s);
	r=0,b=0,g=0;	
		for(int i=0;s[i];i++)
		if(s[i]=='R')
		r++;
		else if(s[i]=='G')
		g++;
		else
		b++;
		
		if(r>=g&&r>=b)
		{
			printf("%d\n",(g+b));
		}
		else if(b>=r&&b>=g)
		{
			printf("%d\n",(r+g));
		}
		else
		printf("%d\n",(r+b));	

		
	}
	
	return  0;
}
