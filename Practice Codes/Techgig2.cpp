#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int ans = 0,lp = input1[0],rp= input1[0];
	for(int i = 1;i<n;i++)
	{
		if(a[i]>=a[i-1])
		{
			rp = input1[i];
		}
		else
		{
			ans+=(rp-lp);
			lp = input1[0];
			rp = input1[0];
		}
	}	
				ans+=(rp-lp);
return ans;
	
	return  0;
}
