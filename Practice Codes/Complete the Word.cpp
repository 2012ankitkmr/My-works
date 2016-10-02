#include<bits/stdc++.h>
using namespace std;


char s[50005];
int n;
int has[128];
void stf(int r)
{
	queue<char>st;
	
	for(int i = 0;i<26;i++)
	if(has['A'+i]==-1)
	{
	st.push('A'+i);
//	cout<<'A'+i<<endl;
}
//	cout<<s<<endl;

 for(int i = r-26+1;i<=r;i++)
	{
		if(s[i]=='?')
		{
			char c = st.front();
			st.pop();
			s[i]=c;
		
		}
	}
	for(int i = 0;i<n;i++)
	{if(s[i]=='?')
    {	
	s[i]='A';
	}
	}
}

int main()
{
	//freopen("in.txt","r+",stdin);
	memset(has,-1,sizeof has);
	scanf(" %s",s);
	n = strlen(s);	
//	cout<<s<<endl;
	int cnt = 0,in,lp=0;
	for(int i =0;i<n;i++)
	{
		if(s[i]=='?')
		cnt++;
		else if(has[s[i]]==-1)
		{
			has[s[i]]=i;
			cnt++;
		}
		else
		{
			in = has[s[i]];
			while(lp<=in)
			{
				if(s[lp]=='?')
				{
				cnt--;
				lp++;
				continue;
			}
				has[s[lp]]=-1;
				cnt--;
				lp++;
			}
			has[s[i]]=i;
			cnt++;
		}
	//	cout<<cnt<<endl;
		if(cnt==26)
		{
//	cout<<i<<endl;		
			stf(i);
			cout<<s;
			return 0;
		}
	}
	printf("-1\n");
	return  0;
}
