#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[102];
	int t,chef,opp,flag;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		chef=0,opp=0;
		flag=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='1')
			chef++;
			else
			opp++;
			if(chef==11)
			{
				if(opp==10)
				{
					chef--;
					opp--;
				}
				else
				{
				flag=1;
				break;
				}
			}
			if(opp==11)
			{
				if(flag==10)
				{
					chef--;
					opp--;
				}
				else
				break;
			}
		}
		if(flag)
		printf("WIN\n");
		else
		printf("LOSE\n");
	}
	return 0;
}
