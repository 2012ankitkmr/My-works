#include<bits/stdc++.h>
using namespace std;

class MatchNumbersEasy
{
	String maxNumber(int[] matches, int n)
	{
		int num=sizeof(matches)/sizeof(int);
		int maxval=0,tempval,sum;
		for(int i=n-1;i>=0;i++)
		{
			tempval=0;
			sum=0;
			for(int j=i;j>=0;j++)
			{
			sum+=matches[j];
			if(sum<=n)
			{
				tempval=tempval*10+j;
			}
			else
			sum-=matches[j];	
			}
			
			
		}
		
		
	}
	
}
