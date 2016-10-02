#include <bits/stdc++.h>
#include<vector>
using namespace std;

#define mod 1000000000
	long long int  arr[2005], sum[2005], array[2005], ans; 
int countFact(int n, int p)
{
    int k=0;
    while (n>0)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 

long long int PowerFact(int a, int b)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod; 
        b /= 2;
    }
    return x;
}
 
long long int C(int n, int r)
{
    long long res = 1;
    vector<bool> isPrime(n+1,1);
    for (int i=2; i<=n; i++)
        if (isPrime[i])
        {
            for (int j=2*i; j<=n; j+=i)
                isPrime[j]=0;
            int k = countFact(n,i) - countFact(r,i) - countFact(n-r,i);  
            res = (res * PowerFact(i, k)) % mod;
        }
    return res;
}
 
int main()
{
	int t, n, m,i,j; 

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for(i=0;i<=m;++i) {
			if (!i) arr[i] = 1;
			else {
				arr[i] = C(m - 1 + i, i);
			}
		}
		for(i=1;i<=n;++i) {
			ans = 0;
			if (i == 1) {
				for(j=0;j<=m;++j) {
					array[j] = arr[j];
				}
			} else {
			for(j=0;j<=m;++j) {
					array[j] = (arr[j] * sum[j]) % mod;
				}
			}
			memset(sum,0,sizeof sum);
			for(j=0;j<=m;++j) {
				if (!j) sum[j] = 1; 
				sum[j] = (sum[j - 1] + array[j]) % mod;
			}
			ans = sum[m];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
