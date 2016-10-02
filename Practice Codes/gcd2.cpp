#include<bits/stdc++.h>
using namespace std;
#define get1(a) scanf("%ld", &a) 
#define wez(n) int (n); scanf("%d",&(n)); 
#define tests wez(testow)while(testow--) 
#define put1n(x) printf("%ld\n",x);
#define getS(x) scanf("%s", x) 

int num(char b[],int a)
{
	int p=0;
	for(int i=0;b[i];i++)
	{
		p=((b[i]-'0')+p*10)%a;
	}
	return p;
}
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	int a,ans,p;
	char b[300];
	tests
	{
		get1(a);
		getS(b);
	if(a==0)
	{
		printf("%s\n",b);
		continue;
	}
		p=num(b,a);
	
		ans=gcd(a,p);
	
		put1n(ans);
		
	}
	return 0;
}
