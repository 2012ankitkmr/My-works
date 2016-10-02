#include<bits/stdc++.h>
using namespace std;

int has[1005];
int main()
{
	//memset(has,0,sizeof has);
	int n,temp,window=0,flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&temp);
	has[temp]=1;
}
	for(int i=1;i<=2;i++)
	window+=has[i];
	for(int i=3;i<=1000;i++)
	{
		if(has[i])
		window++;
		window-=has[i-3];
		if(window>=3)
		{
		flag=1;
		break;
	    }
	    //printf("%d\n",window);
	}
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
