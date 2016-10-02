#include<bits/stdc++.h>
using namespace std;

#define D 0
int k,cnt0[1000006],n,location[1000006];
char s[1000006];
void preprocess()
{
	int cnt =0;
	for(int i = 0;i<n;i++)
	if(s[i]=='0')
	{
	cnt++;	
	}
	else
	{
		cnt0[i]=cnt;
		cnt=0;
	}
	int num1 = 1;
	for(int i = 0;i<n;i++)
	if(s[i]=='1')
	location[num1++]=i;
}
long long sum(long long a)
{
	return (((a+1)*a)>>1);
}
long long calculate()
{
	long long ans =0,cnt=0;
	for(int i = 0;i<n;i++)
	if(s[i]=='0')
	cnt++;
	else
	{
		ans+=sum(cnt);
		cnt=0;
	}
		ans+=sum(cnt);
		cnt=0;
return ans;
}

long long dp[1000006];
int main()
{
	scanf("%d",&k);
	scanf(" %s",s);
	n = strlen(s);
	preprocess();
	int cnt1 =0,cnt=0;
	dp[0]=0;
	if(k==0)
	{
		cout<<calculate();
	return 0;
	}
	for(int i = 0;i<n;i++)
	{
		
		if(s[i]=='1')
		cnt1++;
		
		if(cnt1<k)
		continue;
		
		if(i==0)
		{
		dp[0]=1;
		continue;
	    }
	    if(s[i]=='1')
	    {
	    cnt = cnt0[location[cnt1-k+1]];
		dp[i] = dp[i-1]+cnt+1;	
	    }
	    else
	    {
	    dp[i]= dp[i-1]+cnt+1;	
	    }

	}
	if(D)
for(int i = 0;i<n;i++)
cout<<i<<"="<<dp[i]<<endl;
	
	
	cout<<dp[n-1];
	
	return 0;
}
