#include<bits/stdc++.h>
using namespace std;

class EmoticonsDiv2{
	public:
int dp[1003][2003];
void compute(int message,int clipboard,int moves)
{
	if(message>1000)
	return;
	if(dp[message][clipboard]!=1111111)
	return;
	dp[message][clipboard]=moves;
	compute(message,message,moves+1);
	compute(clipboard+message,clipboard,moves+1);
	

}
int printSmiles(int smiles)
{
for(int i=0;i<1002;i++)
for(int j=0;j<1002;j++)
dp[i][j]=1111111;
	compute(1,0,0);
	int temp;
		temp=1111111;
	for(int j=0;j<1002;j++)
	temp=min(temp,dp[smiles][j]);
return temp;

}
};
