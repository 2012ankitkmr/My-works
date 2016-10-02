#include<bits/stdc++.h>
using namespace std;


long long findpalin_no(char s1[],long long int len)
{
	long long num=0,cnt=0,rev_num=0;
	long long int bit =0;
	for(long long int i=0;i<len;i++)
	{
		bit=(s1[i]=='1')?1:0;
		num=num*2+bit;
		rev_num=rev_num+bit*pow(2,i);	
		if(rev_num==num)
		cnt++;
	}
	return  cnt-1;	
	
}
char s[5000008],t[5008];

int main()
{
	long long test,len,templen;
	long long ans;
	for(scanf("%lld",&test);test--;)
	{
	scanf(" %s",s);	
	len=strlen(s);
	ans=0;
	for(long long int i=len;i>=1;i--)
	{
		s[i]=s[i-1];
	}
	len++;
	//cout<<len;
	for(long long int ind=1;ind<=len/2;ind++)
	{
	for(long long int jump=2;jump*ind<len;jump++)
	{
	//	for(long long int j=0;j<templen;j++)
	//	t[j]=0;
		templen=0;
	for(long long int i=ind;i<len;i=i*jump)
	{
		t[templen++]=s[i];
	//	printf("%d\n",i);
	}	
//	printf("%s,%d,%lld\n",t,templen,findpalin_no(t,templen));
	ans+=findpalin_no(t,templen);		
	}	
	}
	printf("%lld\n",ans+len-1);
}
	return  0;
}
