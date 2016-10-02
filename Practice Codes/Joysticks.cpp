#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int a , b , cnt = 0;
	scanf("%d%d",&a,&b);
	
	while(1)
	{
		if(a==0||b==0)
		break;
		if(a<=1&&b<=1)
		break;
		if(a>=b)
		{
			a-=2;
			b+=1;
		}
		else
		{
			a+=1;
			b-=2;
		}
	//	printf("%d %d\n",a,b);
		cnt++;
	}
	printf("%d\n",cnt);
	return  0;
}
