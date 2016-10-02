#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[100005];

string rev(string st)
{
	string temp(st);
	reverse(temp.begin(),temp.end());
	return temp;
}

string s[100005],rs[100005];
bool compare(string A,string B)
{
	if(A.size()==B.size())
	{
		for(int i = 0;i<A.size();i++)
		{
		if(A[i]>B[i])
			return false;
		else if(A[i]<B[i])
	    	return true;
			
		}
		return true;
	}
	else
	{
		for(int i = 0 ; i < min(A.size(),B.size());i++)
		{
		if(A[i]>B[i])
			return false;
		else if(A[i]<B[i])
	    	return true;
			
		}
		
		return A.size()<B.size();
	}
	
}

ll dp[100005][2];


ll compute(int pos,string str,int type)
{
if(pos==n)
return 0;
if(dp[pos][type]!=-1)
return dp[pos][type];

ll ans = 1e15;


	if(compare(str,s[pos]))
	{
		ans = min(ans,compute(pos+1,s[pos],0));
	}
	if(compare(str,rs[pos]))
	{
		ans = min(ans,a[pos] + compute(pos+1,rs[pos],1));
	}
	
	return dp[pos][type] = ans;
}


int main()
{
memset(dp,-1,sizeof dp);	
scanf("%d",&n);
for(int i = 0;i<n;i++)
cin>>a[i];

getchar();

for(int i = 0;i<n;i++)
{
cin>>s[i];
rs[i] = rev(s[i]);
}
string ss;
ll ans =compute(0,ss,0);
	if(ans>=1e15)
	printf("-1\n");
	else
	cout<<ans;
	return  0;
}
