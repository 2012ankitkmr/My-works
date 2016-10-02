#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long a[1003],C[1003][1003],total = 0,res;
int main()
{
	int k;
	scanf("%d",&k);
	C[0][0] = 1;
	for (int i = 1; i < 1002; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
      }
    }
	for(int i = 0 ; i < k ; i++)
	{
		scanf("%d",&a[i]);
	}
	total = 0;
	res = 1;
	for(int i = 0; i < k ; i++)
	{
		
	res = (res * C[total + a[i] -1][a[i] - 1]) % MOD;
//	cout<<C[total+a[i]-1][a[i]-1]<<endl;
	total += a[i];
	}
	cout<<res;
	return  0;
}
