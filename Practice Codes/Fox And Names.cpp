#include<bits/stdc++.h>
using namespace std;


char s[102][102];
map<char,int>mp;
vector<int>vec[102];
	int has[125];

int main()
{
	freopen("in.txt","r+",stdin);
	int n;
	
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%s",s[i]);
int fl=0;

	for(int i = 1; i<=n ; i++)
	{
		
		for(int j = 0;s[i][j];j++)
		{
			
		if(mp[s[i][j]])
		{
			if(mp[s[i][j]]==j*100+i-1)
			{
			mp[s[i][j]] = j*100 + i;
			}
			else
			{
				fl=1;
				break;
			}
		}
		else
		{
			mp[s[i][j]] = j*100 + i;
			vec[j].push_back(s[i][j]);
		}
	}

	}
	for(int i = 0;i<100;i++)
	for(int j= 0;j<vec[i].size();j++)
	{
	printf("%c",vec[i][j]);
	has[vec[i][j]]=1;
    }
    for(int i = 'a';i<='z';i++)
    {
    	if(!has[i])
    	printf("%c",i);
    }
	return 0;
}
