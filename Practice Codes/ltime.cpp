#include<stdio.h>
char s[1000000001];
int main()
{
	long int t,i,sum;
	for(scanf("%ld",&t);t--;)
	{
		
		scanf("%s",s);
		sum=0;
		for(i=0;s[i]!='\0';i++)
		{
			if((s[i]-'0')==4)
			sum++;
		}
		printf("%ld\n",sum);	
	}
	return 0;
}
