#include<bits/stdc++.h>
using namespace std;

long long max (long long a,long long b)
{
	return a>b?a:b;
}
long long  max(long long  a, long long  b, long long  c) { return max(max(a, b), c); }
 
long long  maxCrossingSum(long long  arr[], long long  l, long long  m, long long  h)
{
    long long  sum = 0;
    long long  left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    sum = 0;
    long long  right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return left_sum + right_sum;
}
long long  maxSubArraySum(long long  arr[], long long  l, long long  h)
{
   if (l == h)
     return arr[l];
  long long  m = (l + h)/2;
 
   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}




int main()
{
	
	long long  t,n,a[105];
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n);
		for(int i = 0;i<n;i++)
		scanf("%lld",&a[i]);

printf("%lld\n", maxSubArraySum(a,0,n-1));
	}
	
	return 0;
}

