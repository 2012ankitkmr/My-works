#include<bits/stdc++.h>
using namespace std;
#define INR(i,l,r) (l<i&&i<=r)
#define gl(i,L,R) for (int i = L; i < R; i++) 
#define ge(i,L,R) for (int i = L; i <= R; i++)
#define get1(a) scanf("%ld", &a) 
#define wez(n) int (n); scanf("%d",&(n)); 
#define tests wez(testow)while(testow--) 
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000000
#define pb push_back
typedef vector<long int> vec; 

vec hash2,hash4;
bool ans[MAXN+2];
long int prime[MAXN+2];
bool sieve[MAXN+2];
int main()
{
	
	ge(i,2,MAXN)
	{
		if(!sieve[i])
		{
			long int j=2,num;
			while((num=i*j)<=MAXN)
			{
				sieve[num]=1;
				j++;
			}
		}
		
		
	}
	
	long int sum,i=1,j=1,len2=0,n,len4=0;
while(1)
{
	if(i>MAXN)
	break;
	hash2.pb(i);
	j++;
	i=j*j;
	len2++;
}	
i=1,j=1;

while(1)
{
	if(i>MAXN)
	break;
	hash4.pb(i);
	j++;
	i=j*j*j*j;
	len4++;
}
	
	gl(i,0,len2)gl(j,0,len4)
	{
		sum=hash2[i]+hash4[j];
		if(sum<=MAXN&&!sieve[sum])
		ans[sum]=1;
	}
	prime[0]=0;
	prime[1]=0;
	prime[2]=1;
	ge(i,3,MAXN)
	{
		prime[i]=prime[i-1];
		if(ans[i])
		prime[i]++;
	}
	
	tests
	{
	get1(n);	
		
	printf("%ld\n",prime[n]);
	}
	return 0;
}
