#include<bits/stdc++.h>
using namespace std;

char s[100005];
int main()
{
	int flag=0 ,len ;
	scanf("%s",s);
	len = strlen(s);
	
	int here = 0;
	for(int i = 1; i < len;i++)
	{
		if(s[i]=='A'&&s[i-1]=='B')
		{
			for(int j = i + 2 ; j < len ;j++ )
			{
				if(s[j]=='B'&&s[j-1]=='A')
				flag = 1;
			}
			here = 1;		
		}
		if(here)
		break;
	}
here = 0;
		for(int i = 1; i < len;i++)
	{
		if(s[i]=='B'&&s[i-1]=='A')
		{
			for(int j = i + 2 ; j < len ;j++ )
			{
				if(s[j]=='A'&&s[j-1]=='B')
				flag = 1;
			}		
			here = 1;
		}
		if(here)
		break;
	}
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
	
	return 0;
}
