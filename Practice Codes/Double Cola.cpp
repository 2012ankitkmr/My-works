#include<bits/stdc++.h>
using namespace std;



int heads[50];
int main()
{
	string s[5];
	s[0].assign("Sheldon");
	s[1].assign("Leonard");
	s[2].assign("Penny");
	s[3].assign("Rajesh");
	s[4].assign("Howard");
	
	int n,a,st,b;
	scanf("%d",&n);
	
	a = (n-1)/5;
	b = log2(a+1);
	
	st = 5;
	for(int i = 1;st<=1e9;i++)
	{
		heads[i] = heads[i-1]+st;
		st = st*2;
	}
	cout<<s[(n-1-heads[b])>>b];
	
	return 0;
}
