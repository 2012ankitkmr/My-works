#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string bfs(ll n)
{
	if(n==1)
	return "1";
	string ans;
	pair<string,ll>current;
queue<pair<string,ll> >q;
ll  next_val;
q.push(make_pair("1",1));
while(!q.empty())
{
	current=q.front();
	q.pop();
	string s=current.first;
	ll rem=current.second;
	if(rem==0)
	{
		ans=s;
		break;
	}
	next_val=(rem*10)%n;
	if(next_val==0)
	{
		ans=s+'0';
		break;
	}
	else
	{
		q.push(make_pair(s+'0',next_val));
	}
	next_val=(rem*10+1)%n;
	if(next_val==0)
	{
		ans=s+'1';
		break;
	}
	else
	{
		q.push(make_pair(s+'1',next_val));
	}
	
}	
return ans;	
}

int main()
{
	ll n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
	string sh;
		sh=bfs(n);
cout<<sh<<endl;
	}
	
	return 0;
}
