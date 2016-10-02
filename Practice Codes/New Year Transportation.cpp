#include<bits/stdc++.h>
using namespace std;


int a[30004];
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	
	for(int i =1;i<=n-1;i++)
	scanf("%d",&a[i]);
	
	int ptr=1;
	for(int i =1;i<=n;)
	{
		
		if(ptr==t)
		{
			printf("YES\n");
			return 0;
		}
		if(ptr==n)
		break;
		ptr = a[i]+i;
		i=ptr;
	}	
	
	if(ptr==t)
		{
			printf("YES\n");
}
else
printf("NO\n");
return 0;
}
