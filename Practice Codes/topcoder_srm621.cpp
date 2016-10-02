#include<bits/stdc++.h>
using namespace std;
#define gl(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define ge(i,L,R) for (int i = L; i <= R; i++)

#define pb push_back
typedef vector<int> vec; 


class NumbersChallenge{
	public:
		int MinNumber(vec S)
		{
		vec v=S;
		long sum=0;
		int num=S[0];
		v[0]=0;
		v.pb(num);
		
		for(auto x:v)
		sum+=x;
		sort(v.begin(),v.end());
		int n=(int)v.size();
		int row=n+1;
		int col=n*100000+2;
		vector<vector<int> >subset(v.size()+1,vector<int>(col+1,0));
		gl(i,0,row)
		subset[i][0]=1;
		gl(i,1,col)
		subset[0][i]=0;
		gl(i,1,row)
		{
			gl(j,1,col)
			{
				subset[i][j]=subset[i-1][j]||((v[i]<=j)&&(subset[i-1][j-v[i] ]));
			}
		}
		int ans=1;				
		for(ans=1;ans<col;ans++)
		{
			if(subset[n][ans]==0)
			break;
		}
		return ans;	
		}
	
	
};
