#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	//freopen("in.txt","r+",stdin);
char s[15];
int t;
vector<string>seq;
for(scanf(" %d",&t);t--;)
{
	scanf("%s",s);
	int cnt = 0;
	seq.clear();
	for(int i = 0;s[i];i++)
	{
		if(s[i]=='X')
		{
			seq.push_back("1x12");
			cnt++;
			break;
		}
	}
	for(int i = 6;s[i];i++)
	{
		if(s[i]==s[i-6]&&s[i]=='X')
		{
			seq.push_back("2x6");
			cnt++;
			break;
		}
	}
	
	for(int i = 8;s[i];i++)
	{
		if(s[i]==s[i-4]&&s[i]==s[i-8]&&s[i]=='X')
		{
			seq.push_back("3x4");
			cnt++;
			break;
		}
    }
	for(int i = 9;s[i];i++)
	{
		if(s[i]==s[i-3]&&s[i]==s[i-6]&&s[i]==s[i-9]&&s[i]=='X')
		{
			seq.push_back("4x3");
			cnt++;
			break;
        }
    }	
	for(int i = 10;s[i];i++)
	{
		if(s[i]==s[i-2]&&s[i]==s[i-4]&&s[i]==s[i-6]&&s[i]==s[i-8]&&s[i]==s[i-10]&&s[i]=='X')
		{
			seq.push_back("6x2");
			cnt++;
			break;
		}
    }
    int x =0;
    for(int i = 0;s[i];i++)
    {
    	if(s[i]=='X')
    	{
    		x++;   		
    	}
     }
     
     if(x==12)
     {
     		seq.push_back("12x1");
			cnt++;
     }
	printf("%d ",cnt);
	
	for(int i = 0;i<seq.size();i++)
	{
cout<<seq[i]<<" ";
	}
	printf("\n");
}	
	
	return 0;
}
