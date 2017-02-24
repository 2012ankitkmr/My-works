#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+5

using namespace std;
 
#define MAXN 5005
 
int n, m, type[MAXN], dp[MAXN];
 
int main() {    
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		double x;
		scanf("%d %lf", type+i, &x);
	}
 
	for(int i = 1; i <= n; i++) {
		int j = type[i];
		for(int k = j; k >= 1; k--) {
			dp[j] = max(dp[j], 1+dp[k]);
		}
	}
 
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", n-ans);
}
