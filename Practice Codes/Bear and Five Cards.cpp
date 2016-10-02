#include<bits/stdc++.h>
using namespace std;

int t[7];
int cnt[101];
int main()
{
	int sum = 0;
	for(int i = 0; i < 5;i++)
	{
	scanf("%d",&t[i]);
	cnt[t[i]]++; 
	sum+=t[i]; 
}
int ans = 0;
for(int i = 1 ;i<101;i++)
if(cnt[i]>=2)
{
	ans = max(ans,i*min(cnt[i],3));
}
printf("%d\n",sum-ans);
	
	return 0;
}
