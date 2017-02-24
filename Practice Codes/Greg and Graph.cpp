#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
int mat[502][502],temp[502][502];
int seq[502];
stack<ll>ans;
int main()
{
//	freopen("in.txt","r+",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=n;j++)
	scanf("%d",&mat[i][j]);
	
	for(int i = 1;i<=n;i++)
	scanf("%d",&seq[i]);
	
	
	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=n;j++)
	if(i!=j)
	temp[i][j]=mat[i][j];

	ll num;

	for(int b = n;b>=1;b--)
	{
		for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
		{
		temp[i][j] = min(temp[i][j],temp[i][seq[b]]+temp[seq[b]][j]);
		temp[j][i] = min(temp[j][i],temp[j][seq[b]]+temp[seq[b]][i]);

}
		num = 0LL;
	
		for(int i = n;i>=b;i--)
		{
			for(int j = n;j>=b;j--)
			{
				num+=temp[seq[i]][seq[j]];
			}
		}
		ans.push(num);
	}
	while(!ans.empty())
	{
	printf("%I64d ",ans.top());
		ans.pop();		
	}
	return 0;
}
