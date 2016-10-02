#include<bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		char s[5050];
		scanf("%s",s);
		if(s[0]=='0'&&s[1]=='\0')
	    break;
		long int i,dp[5005];
		dp[0]=1;
		int p;
		for(i=1;s[i]!='\0';i++)
		{
		dp[i]=dp[i-1];
		p=(int)(s[i-1]-'0')*10+(int)(s[i]-'0');
	//printf("p=%d\n",p);
		if(p<=26&&p>=1&&s[i]!='0'&&s[i-1]!='0'&&s[i+1]!='0')
		{ //printf("here%d\n",p);
			dp[i]=dp[i]+dp[i-2<0?0:i-2];
		}   
	//	printf("dp[%ld]=%ld\n",i,dp[i]);
		}
		printf("%ld\n",dp[i-1]);
	}
	
	return 0;
}
