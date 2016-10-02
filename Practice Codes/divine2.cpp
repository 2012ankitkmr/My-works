#include<bits/stdc++.h>
using namespace std;

int main()
{char s[100005];
	long int t;
long long int sum,ans;
	for(scanf("%ld",&t);t--;)
	{
	scanf("%s",s);	
	sum=0,ans=0;
	for(long int i=0;s[i]!='\0';i++)
	{
		sum=sum+(s[i]-'0');
	}	
	
	if(!sum%9)
	{
		printf("0\n");
		continue;
	}
	
	ans=min(sum%9,9-sum%9);	
	
	if((s[0]-'0')!=9)
	{
		if(ans>=(s[0]-'0'))
		ans=9-ans;
	}
	
	printf("%lld\n",ans);
	
	}
	return 0;
}
