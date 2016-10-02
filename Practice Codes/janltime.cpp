#include<stdio.h>
long long int multiply(long long int a,long long int b,long long int mod){
    if(b>a)return multiply(b,a,mod);
    if(b==0)return 0;
    if(b==1)return a;
    long long int res = multiply(a,b>>1,mod);
    res+=res;
    while(res>=mod)res-=mod;
    if(b&1)res+=a;
    while(res>=mod)res-=mod;
    return res;
}

long long int FastPower(long long int a,long long int b,long long int mod){
    if(a<=1)return a;
    long long int res=1;
    while(b){
        if(b&1){
            res = multiply(res,a,mod);
        }
        a =  multiply(a,a,mod);
        b>>=1;
    }
    return res;
}




/*
long long int po(long long int a,int k,long long int m )
{
int i;
long long int j;
if(k==0)
return 1;
else if(k==1)
return a;

else
{
j=a%m;
a=a%m;
	for(i=1;i<k;i++)
	{
		a=(a*j)%m;
	}
	
	return a;
	}
}
*/
int main()
{
	int t,i;
	long long int key,m,a,ans;
	char s[10100];
	for(scanf("%d",&t);t--;)
{
	scanf("%lld",&m);
	scanf("%s",s);
	a=1;
	for(i=0;s[i]!='\0';i++)
	{
	  key=0;
	//printf("i=%d\n",i);
	 while((s[i]>='0')&&(s[i]<='9'))
	 {
	 	key=multiply(key,10,m);
		 key=key+(s[i]-'0');
		 i++;
		 while(key>=m)
		 key=key-m;
		  }
	 i+=2;
	//printf("i=%d\n",i);
	  ans=1;
	 while((s[i]>='0'&&s[i]<='9')&&(s[i]!='\0'))
	 {
	    ans=FastPower(ans,10,m);
		 	ans=multiply(ans,FastPower(key,s[i]-'0',m),m);
		 	i++;
	}
	 	a=multiply(ans,a,m);
		//printf("ans=%lld\n",ans);	
			//printf("a=%lld\n",a);	
	}
	printf("%lld\n",a);
	
}	
	return 0;
}
