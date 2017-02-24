#include<bits/stdc++.h>
using namespace std;

char s[100005];

int main()
{
	scanf(" %s",s);
	int tw[5],th[5],fo[3];
	tw[0]=6,tw[1]=2,tw[2]=4,tw[3]=8;
	th[0]=1,th[1]=3,th[2]=9,th[3]=7;
	fo[0]=6,fo[1]=4;
	int len = strlen(s),num,num1,num2,ans=0;
	
	if(len<=1)
	{
		
		num = s[0]-'0';
		if(num==0)
ans= 4;
		else
		{
		num1 = num%4;
		ans = 1+tw[num1]%5+th[num1]%5;
		num2 = num%2;
		ans = ans+(fo[num2]%5);
//		printf("%d %d %d\n",tw[num1],th[num1],fo[num2]);
     	}
	}
	else
	{
		num = 10*( s[len - 2] - '0') + ( s[len - 1 ] - '0' );
		num1 = num%4;
		ans = 1+tw[num1]+th[num1];
		num2 = num%2;
		ans = ans+fo[num2];		
	}
	printf("%d\n",ans%5);
	
	
	return 0;
}
