#include<bits/stdc++.h>
using namespace std;
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)
#define get1(a) scanf("%ld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define wez(n) int (n); scanf("%d",&(n)); //handy if the input is right after the definition of a variable
#define tests wez(testow)while(testow--) //for multilple cases problems
#define fi first
#define se second
//for vectors
#define pb push_back

bool sieve[10000004];
vector<long int>primes;
pair<long int,long int>pa[10000004];
//long int primes[2000004];


long nways(long int  n)
{
	long int factor=n,res=0;
for(long int i=2;i<=factor;i++)
{
	
	if(factor%i==0)
	{
		res++;
		factor=factor/i;
	}
	
}
return res+1;
}
int main()
{
	ge(i,2,10000000)
	{
		if(!sieve[i])
		{
			int j=2,num;
			while((num=i*j)<=10000000)
			{
				sieve[num]=1;
				j++;
			}
			
		}
	}
ge(i,2,10000000)
{
	if(!sieve[i])
	primes.pb(i);
}
long int n,sqr,temp;
while(1)
{
get1(n);
if(n==0)
break;
if(!sieve[n])
{
	printf("%ld = %ld",n,n);
	printf("\nWith %ld marbles, %ld different rectangles can be constructed.\n",n,1);
	
}
else
{
	sqr=(int)sqrt(n);
	temp=n;
	long int ind=0,cnt,size=0;
	while(1)
	{
		if(primes[ind]>sqr)
		break;
		if(!(temp%primes[ind]))
		{
			
			cnt=0;
			while(!(temp%primes[ind]))
			{
			temp/=primes[ind];
			cnt++;	
			}
			pa[size].fi=primes[ind];
			pa[size].se=cnt;
			size++;
		}
		ind++;	
	}


	printf("%ld = ",n);
	if(size)
	{
	
	gl(i,0,size-1)
	gl(j,0,pa[i].se)
	{

		printf("%ld * ",pa[i].fi);
	}
	gl(j,0,pa[size-1].se-1)
{
printf("%ld * ",pa[size-1].fi);
}	
{
printf("%ld",pa[size-1].fi);
}
}
else
{
	printf("%ld",n);
}
	printf("\nWith %ld marbles, %ld different rectangles can be constructed.\n",n,nways(n));

}



}

	
	return 0;
}
