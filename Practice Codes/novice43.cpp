#include<bits/stdc++.h>
using namespace std;
int len;
bool Isvalid(char s[])
{
}
long int compute(char s[],int n)
{
	if(!Isvalid(s))
	return 0;
	long int cnt=0;
	for(int i=0;i<=n;i++)
	{
		s[n]++;
		cnt+=(compute(s,n-1));
	}
	return cnt;
}
int main()
{
	int t,n;
	char s[15];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		len=n;
		for(int i=0;i<n;i++)
		s[i]='a';
		//s[i]='\0';
		long ans=compute(s,n-1);
		printf("%ld\n",ans);
	}
	
	return 0;
}

