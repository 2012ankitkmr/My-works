#include<bits/stdc++.h>
using namespace std;

int n,q;
string s[40];
char c[40];

long long compute(int len,int tomake)
{
	if(len==n)
	return 1;
	long long ans = 0;
	string temp;
	for(int i = 0;i<q;i++)
	{
		if(c[i]==(tomake+'a'))
		{
			temp = s[i];
			char ch = temp[0];
			ans+=compute(len+1,ch-'a');
		}
		
	}
	
return ans;	
}



int main()
{
//	freopen("in.txt","r+",stdin);
	scanf("%d%d",&n,&q);
//	getchar();
	for(int i =0;i<q;i++)
	{
		cin>>s[i]>>c[i];
	
	}
	cout<<compute(1,0);
	
	return  0;
}
