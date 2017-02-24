#include<bits/stdc++.h>
using namespace std;


int n;
int a[100005];
int ceilInd(int lo,int hi,vector<int>&vec,int data)
{
	while(hi-lo>1)
	{
		int m = lo + (hi-lo)/2;
		if(vec[m]>=data)
		hi = m;
		else
		lo = m;
	}
	return hi;
}

int main()
{
	scanf("%d",&n);
	for(int i = 0 ; i < n;i++)
	scanf("%d",&a[i]);
	int len = 1;
vector<int>vec(100000,0);
vec[0]=a[0]	;
	for(int i = 1 ; i < n ;i++)
	{
		if(a[i]<vec[0])
		{
			vec[0]=a[i];
		}
		else if(a[i]>vec[len-1])
		{
			vec[len++]=a[i];
		}
		else
     	{
     		vec[ceilInd(-1,len-1,vec,a[i])]=a[i];  		
	    }
		
	}
	printf("%d\n",len);
	return 0;
}
