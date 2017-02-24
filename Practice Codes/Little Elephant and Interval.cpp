#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int find_len(ll a)
{
	int len = 0;
while(a)
{
	a/=10;
	len++;
}
	return len;
	
}


ll find (ll a)
{
if(a<=9)
return a;
int len = find_len(a);
ll l[20];
ll res=0;
l[1]=9;
l[2]=18;
for(int i = 2;i<=19;i++)
{
	l[i] = 9*pow(10,(i-2))+l[i-1];
}
res+=l[len-1];
int h =(a/pow(10,len-1));
res+=((h-1)*pow(10,len-2));

a= a%((ll)pow(10,len-1));
if((a%10)>=h)
res++;
res+=(a/10);
	return res;
}



int main()
{
	ll l,r;
	cin>>l>>r;
	ll ans = find(r)-find(l-1);
	cout<<ans; 
	return 0;
}
