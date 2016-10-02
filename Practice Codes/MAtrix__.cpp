#include <iostream>
#include <cstdio>
 
using namespace std;
 
int min(int a, int b, int c) {
	int temp;
	temp = a;
	if(b < a) {
		temp = b;
	}
	if(c < temp) {
		temp = c;
	}
	return temp;
}
int main()
{
	
	int t, m, n;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				a[i][j]=1-a[i][j];
				if(i == 0 || j == 0) {
					dp[i][j] = a[i][j];
				}
			}
		}
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				if(a[i][j] == 1) {
					
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				}
				else {
					dp[i][j] = 0;
				}
				
			}
		}
		int max,sum=0;
		max = dp[0][0];
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				printf("%d ",dp[i][j]);
				if(dp[i][j] > max) {
					max = dp[i][j];
				}
	sum+=dp[i][j];
			}
									printf("\n");

		}
		printf("%d\n", sum);
	}
	return 0;
		
}
 
