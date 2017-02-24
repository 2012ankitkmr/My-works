#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	printf("%d",max(a*b+c,max(a*(b+c),max(a+b*c,max((a+b)*c,max(a*b*c,a+b+c))))));
	
	return 0;
}
