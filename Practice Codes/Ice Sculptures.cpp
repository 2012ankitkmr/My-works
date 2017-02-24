#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>vec;
int main()
{
	int sum,x,y,n,a[20004],ans = INT_MIN;
	cin>>n;
	for(int i = 1 ; i <= sqrt(n) ; i++)
	{
		if(n%i==0)
		{
			x = i;
			y = n/i;
			vec.pb(x);
			if(x!=y)
			vec.pb(y);
		}
	}
	
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i = 0;i<vec.size();i++)
	{
//		printf("%d\n",vec[i]);
		if((n/vec[i])<3)
		continue;
		for(int j = 0;j<vec[i];j++)
		{
			 sum = 0;
			for(int k = j ; k<n;k+=vec[i])
			sum+=a[k];
			ans = max(ans,sum);
		}
		
	}
	printf("%d\n",ans);
	return 0;
}
