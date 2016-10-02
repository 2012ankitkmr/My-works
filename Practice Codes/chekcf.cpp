#include<stdio.h>
#include<math.h>
long int A[10000007];
#define MOD 1000000007

int mi[10000007][24];
long int min(long int a,long int b)
{
	return a>b?b:a;
}
long long int fast_pow(long int base,long int pow,long int mod)
{
	if(pow == 1)
		return base;
	if(pow == 0)
		return 1;
	long long int temp = fast_pow(base,pow/2,mod)%mod;
	if(pow % 2 == 0)
	{
		return (temp%mod* temp%mod)%mod;
	}
	else
	{
		return (temp%mod * temp%mod * base%mod)%mod;
	}
}
long int RMQ(long int i,long int j)
{
	long int k;
	k= log2(j-i+1);
	return min(A[mi[i][k]], A[mi[j- (1<<k) + 1][k]]);
}


int main()
{
	long int n,k,q,a,j,b,c,d,e,f,L,R,r,s,t,m,L1,La,Lc,Lm,D1,Da,Dc,Dm,i,min1;
	long long int product,sum;
	scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld%ld",&n,&k,&q,&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[1],&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
A[0] = 0;
//generate array
for(i=2;i<=n;i++)
{	if(fast_pow(t,x,s)  <= r)       
			A[x] = (a%m*A[x-1]%m*A[x-1]%m + b%m*A[x-1]%m + c%m) % m;
		else
			A[x] = (d%m*A[x-1]%m*A[x-1]%m + e%m*A[x-1]%m + f%m) % m;

}
//for(i=1;i<=n;i++)
//printf("a=%ld\n",A[i]);
	for(int i=0; i<=N; i++)
		mi[i][0] = i;
 

	for(int j=1; 1<<j <=n ; j++ )
	{
		for(int i=1; i+(1<<j)-1 <=n; i++)
		{
			if(A[mi[i][j-1]] < A[mi[i + (1<<j-1)][j-1]])
				mi[i][j] = mi[i][j-1];
			else
				mi[i][j] = mi[i + (1<<j-1)][j-1];
		}
	}
 


sum=0;
product=1;
//generate range
for(i = 1;i<=q;i++)
{
	L1 = ((La%Lm * L1%Lm)%Lm + Lc%m) % Lm;
	D1 = ((Da%Dm * D1%Dm)%Dm + Dc%Dm) % Dm; 
	L = L1 + 1;
	R = (long int)min(L + k - 1 + D1, n);
	
		min1 = RMQ(L,R);
		sum+=min1;
		product= (product%MOD * min1%MOD)%MOD;
sum=sum+min1;
product=(product*(min1%MOD))%MOD;

}
printf("%lld %lld",sum,product);
	
	return 0;
}

