#include<bits/stdc++.h>
using namespace std;
#define ll long long 
map<ll,int>mymap[26];
char s[100005];

ll dp[100005];
int occ[26],a[28];
int main()
{
//	freopen("in.txt","r+",stdin);
	for(int i = 0;i<26;i++)
	scanf("%d",&a[i]);
	scanf(" %s",s);
int n = strlen(s);
dp[0] = a[s[0]-'a'];
for(int i = 1; i < n ;i++)	
	dp[i] = dp[i-1] + a[s[i]-'a'];

ll ans= 0;

for(int i = 0; i < n ; i++)
{
if(!occ[s[i]-'a'])
{
	mymap[s[i]-'a'][dp[i]]=1;	
	occ[s[i]-'a']=1;
}
else
{
	ans+=mymap[s[i]-'a'][dp[i-1]];
	mymap[s[i]-'a'][dp[i]]++;	
}

}	
	cout<<ans;
	return 0;
}
