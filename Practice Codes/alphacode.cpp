#include<stdio.h>
#include<string.h>
int main()
{
char s[5005];
long int i,len,dp[5005];
long int c1,c2;
	scanf("%s",s);
	len=strlen(s);
while(s[0]!='0')
{
dp[0]=1;dp[1]=1;
	for(i=2;i<=len;i++)
	{
		dp[i]=0;
		c1=s[i-2]-'0';c2=s[i-1]-'0';
		
		if(c1==1||(c1==2&&c2<=6))
		dp[i]+=dp[i-2];
		if(c2!=0)
		dp[i]+=dp[i-1];
		
	}
	printf("%ld\n",dp[len]);
	
	scanf("%s",s);
	}
	
	return 0;
}
