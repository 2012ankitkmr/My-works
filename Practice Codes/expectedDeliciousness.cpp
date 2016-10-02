#include<bits/stdc++.h>
using  namespace std;


class RandomPancakeStackDiv2
{
	public:
	double dfs(int n,int m,vector<int> d)
	{
		double res=d[m];
		for(int i=0;i<m;i++)
		res+=1/(n)*dfs(n-1,i,d);
		return res;
		
	}
	
	
	double expectedDeliciousness(vector<int> d)
	{
		int n=d.size();
		double ans=0;
		for(int i=0;i<n;i++)
		ans+=1/n*dfs(n-1,i,d);		
		return ans;
	}
	
};


int main()
{
	vector<int> a;
	a[0]=1;
	a[1]=1;
	a[2]=1;
	RandomPancakeStackDiv2 obj;
	printf("%lf\n",obj.expectedDeliciousness(a));
	
	return 0;
}
