#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	long int sum,i,len,sum1;
	char s[100005];
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		sum=0;
sum1=0;
		len=strlen(s);

			for(i=0;i<len;i+=2)
			{
				if(s[i]=='+')
				sum++;
			
				if(s[i]=='-')
				sum1++;
			
			}
			for(i=1;i<len;i+=2)
			{
				if(s[i]=='-')
				sum++;
				
				if(s[i]=='+')
				sum1++;
			}	

			if(sum1<sum)
			sum=sum1;
		printf("%ld\n",sum);
	}
return 0;
}
