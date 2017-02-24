#include<bits/stdc++.h>
using namespace std;

vector<string>eight; 
int cnt[150][11];



void precompute()
{
	int cn=0;
for(int i = 104;i<=999;i+=8)
{
	string c ;
	int k = i/100;
	c[0] ='0'+k;
	c[1] ='0'+(i-k*100)/10;
	c[2] = '0'+i%10;
	eight.push_back(c);
	cnt[cn][k]++;
	cnt[cn][(i-k*100)/10]++;
	cnt[cn][i%10]++;
	cn++;
}	
	
}

vector<string> divby8(int n,string s[])
{

precompute();

string ch;
int has[12];
//printf("here");
\
vector<string>ans;
string yes,no;
yes.assign("YES");
no.assign("NO");

for(int i = 0;i<n;i++)
{
ch.assign(s[i]);
if(ch.length()==1)
{

if((ch[0]-'0')%8==0)
ans.push_back(yes);	
else
ans.push_back(no);	

}

else if(ch.length()==2)
{
if(((10*(ch[0]-'0')+(ch[1]-'0'))%8==0)||((10*(ch[1]-'0')+(ch[0]-'0'))%8==0))
ans.push_back(yes);	
else
ans.push_back(no);			
}

else
{
memset(has,0,sizeof has);


for(int j = 0;j<ch.length();j++)
has[ch[j]-'0']++;

int fl,flag=0;
for(int j = 0;j<eight.size();j++)
{
	fl =0;
	for(int k = 0;k<9;k++)
	{
		if(has[k]<cnt[j][k])
		{
			fl=1;
		}
	}
	if(!fl)
	{
		flag= 1;
		ans.push_back(yes);
		break;
	}
	
}
      if(!flag)
		ans.push_back(no);
}

}	
	
	return ans;
}



int main()
{
	int n=2;
	string s[n+1];
	s[0].assign("61");
	s[1].assign("75");
	vector<string>ans = divby8(n,s);
	for(int i = 0;i<ans.size();i++)
cout<<ans[i]<<endl;
	
	return  0;
}
