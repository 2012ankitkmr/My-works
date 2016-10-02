#include<bits/stdc++.h>
using namespace std;

int main()
{
	int rand1,rand2,parity1,parity2;
	freopen("in.txt","w+",stdout);
	printf("50\n");
	for(int i=0;i<50;i++)
	{
	int n=rand()%2000;
	printf("%d\n",n);
	while(n--)
	{
		rand1=rand()%10000;
		rand2=rand()%10000;
		parity1=rand()%2;
		parity2=rand()%2;
		rand1=rand1*pow(-1,parity1);
		rand2=rand2*pow(-1,parity2);
		printf("%d %d\n",rand1,rand2);
	}
	
}
	return 0;
}
