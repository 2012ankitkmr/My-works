#include<stdio.h>
int main()
{
	long int t,l,r;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld%ld",&l,&r);
		
		if((l!=r)||(l==0&&r==0))
		printf("Don't Play\n");
		else
		printf("Play\n");
		
	}
return 0;
}
