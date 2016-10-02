#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,temp,five=0,zero=0;
	char s[]="555555555";
	scanf("%d",&n);
	while(n--)
	{
		cin>>temp;
		if(temp)
		five++;
		else
		zero++;
	}
	if(zero==0)
	{
	printf("-1\n");	
	}
	else
	{

		{
			int seq=five/9;
			for(int i=0;i<seq;i++)
			printf("%s",s);
			if(seq)
			for(int i=0;i<zero;i++)
			printf("0");
			else
			printf("0\n");
		}
	}
	return 0;
}
