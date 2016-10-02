#include <bits/stdc++.h>
using namespace std;

long long ans;
char s[300005];
int main() {
	scanf("%s",s);
	int n = strlen(s);
	int num= 0,prev;
	ans =0;
	for(int i = 0;s[i];i++)
	{
		num = s[i]-'0';

	if(num%4==0)
	ans++;
if(i)
{
	prev= s[i-1]-'0';
	num = prev*10+num;
	if(num%4==0)
	ans+=i;
}
	}
cout<<ans<<endl;	// your code goes here
	return 0;
}
