#include<bits/stdc++.h>
using namespace std;
#define dMOD 1000000007
int cnt[546];
int dp[10000000];

int fib(int n)
{
	
	//cnt[n]++;
	if(n==1)
	return 1;
	if(n==0)
	return 0;
	
//	if(n==7)return 11;
	if(dp[n]!=-1)
	return dp[n];
	
	return dp[n]=(fib(n-1)%dMOD+fib(n-2)%dMOD)%dMOD;
}

double fpow(double a,int p)
{
    double RES = 1.0;
    
    double B =  a;
    while(p > 0)
    {
        if(p%2 == 1) RES = fmod((RES*B),dMOD);
        B = fmod((B*B),dMOD);
        p = p/2;
    }
    double res = (double) RES;
    return res;
}

 
//double modInverse(double a, int m) {
  //  return fpow(a,m-2);
//}
int main()
{
	memset(dp,-1,sizeof dp);
	int n;
	scanf("%d",&n);
int temp = fib(n);
//	for(int i=1;i<=n;i++)
//	printf("%d: %d\n",i,cnt[i]);
	printf("fib is %d\n",temp);

	double phi_b = (1.0-pow(5.0,0.5))/2;
	double phi_a = (pow(5.0,0.5)+1.0)/2; 
	printf("ans=%lf\n",temp/fmod(fpow(phi_a,9999),dMOD));
	//printf("mod inverse=%lf\n",modInverse(2,dMOD));
	
	


	
	return  0;
}
