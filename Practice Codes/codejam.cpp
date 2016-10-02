#include<bits/stdc++.h>
using namespace std;

long long find(long long bit)
{
	long long ans=0;
	while(bit)
	{
		bit/=10;
		ans++;
	}
	return ans;
	
}
long long range[100];
int main()
{
	long long len=1,n=1,no_of_bits,k;
	while(n<=61)
	{
		range[n]=len;
		no_of_bits=find(len);
	//	printf("n=%lld,len=%lld,bits=%lld\n",n,len,no_of_bits);
		n++;
		len=len*2;
		len++;
		
	}

	//for(int i=1;i<=61;i++)
//	printf("%lld\n",range[i]);

freopen("A-large-practice.in","r",stdin);
freopen("out.txt","w+",stdout);
	int t,rev;
	long long parent_length,itlen,itn,tempk;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%lld",&k);
	
		tempk=k;
		rev=0;
		while(1)
		{
		if(tempk==1||(!((tempk)&(tempk-1))))
		break;
		itlen=1,itn=1;
		
		while(itlen<tempk)
		{    itn++;
			itlen=range[itn];
		}
		parent_length=itlen;
	//	printf("parent length=%lld at %lld\n",parent_length,k);
	    
	    tempk=parent_length-tempk+1;
	    rev++;
		 }
		 if(rev&1)
		 printf("Case #%d: 1\n",test);
		 else
		 printf("Case #%d: 0\n",test);
		 
	}
	
	
	return  0;
}
