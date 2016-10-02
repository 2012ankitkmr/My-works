#include<bits/stdc++.h>
using namespace std;


string toLower(string ss)
{
	for(int i = 0 ; i < ss.size() ; i++)
	{
		if(ss[i]>=65&&ss[i]<=90)
		{
			ss[i]= tolower(ss[i]);
		}
	}
	return ss;
}

map<string,int>dp;
int main()
{
	//freopen("in.txt","r+",stdin);
string s;
int n;
scanf("%d",&n);
string st("polycarp");
dp[st]=1;


char *pch,*str;
vector<string>line_token;


int maxval = INT_MIN;
getchar();
//printf("here\n");
for(int i = 0 ; i < n ; i++)
{
	getline(cin,s);

str = strdup(s.c_str());

pch = strtok(str," ");

while(pch!=NULL)
{
	string ss(pch);

	ss = toLower(ss);
//	cout<<ss<<endl;
	line_token.push_back(ss);
	pch = strtok(NULL," ");
}

dp[line_token[0]] = dp[line_token[2]] + 1;


maxval = max(maxval,dp[line_token[0]]);
line_token.clear();
}

printf("%d\n",maxval); 
return  0;
}
