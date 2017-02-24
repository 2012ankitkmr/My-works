#include<bits/stdc++.h>
using namespace std;

int cnt;
int main()
{
	for(int i = 25000000; i<=50005000; i++)
	{
		if(((int)sqrt(i)*(int)sqrt(i))==i)
		{
		printf("perfect square = %d =>%d\n",(int)sqrt(i),i);
		cnt++;
	}
	}
	printf("NO. of elements = %d\n",cnt);
	return 0;
}
