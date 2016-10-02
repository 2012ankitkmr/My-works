#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,has[45],flag;
	char a[1008],b[1008];
	
	for(scanf("%d",&test);test--;)
	{
	scanf(" %s",a);
	scanf(" %s",b);
	memset(has,0,sizeof has);
	for(int i=0;a[i];i++)
	{
	has[(int)(a[i]-'a')]=1;	
	}
	flag=0;
	for(int i=0;b[i];i++)
	{
	if(has[(int)(b[i]-'a')])
	{
	flag=1;	
	break;
    }
	}
	if(flag)
	printf("Yes\n");
	else
	printf("No\n");
	}
	return 0;
}
