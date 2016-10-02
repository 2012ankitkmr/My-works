#include<bits/stdc++.h>
using namespace std;

class  ChooseTheBestOne
{
	public:
	int countNumber(int N){

	bool has[5005];
	memset(has,1,sizeof has);
		int n,ind;
	n=N;
	long long num;
	//scanf("%d",&n);
//	n=4934;
	ind=1;
	for(int i=1;i<=n-1;i++)
	{
		num=(long long)pow(i,3)%(long long)(n-i+1);
		if(num==0)
		num=(n-i+1);
		num--;
	//	printf("%d\n",num);
	while(num--)
	{
		ind++;
	while(has[ind]==0)
	{
	ind++;
		if(ind>n)
		{ind=1;
			while(!has[ind])
			{
				ind++;
			}
		}
	}
	    if(ind>n)
	    {ind=1;
			while(!has[ind])
			{
				ind++;
			}
		}
	}
//	printf("ind=%d\n",ind);
		has[ind]=0;
		num=1;
			while(num--)
	{
		ind++;
	while(has[ind]==0)
	{
	ind++;
		if(ind>n)
		{ind=1;
			while(!has[ind])
			{
				ind++;
			}
		}
	}
	    if(ind>n)
	    {ind=1;
			while(!has[ind])
			{
				ind++;
			}
		}
	}
	}
	for(int i=1;i<=n;i++)
	if(has[i])
	printf("%d\n",i);
}
	
};
