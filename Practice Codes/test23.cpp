#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","w+",stdout);
	printf("10\n50 50\n");
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			printf("%d ",rand()%1000000+1);
		}
		printf("\n");
	}
	
	
	return 0;
}
