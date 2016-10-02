#include<stdio.h>
#include<limits>
#define MAX 100000
long int count;
long int min_smoke(long int arr[],long int i,long int j)
{
	long int min=MAX;		
	if(i==j)
	return 0;
	//if(count[i][j]!=-1)
	//return count[i][j];		
	long int k;
	//count[0]=
	for(k=i;k<=j;k++)
	{
		count=min_smoke(arr,i,k)+min_smoke(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		if(count<min)
		min=count;
	}
			return min;
}


int main()
{
	long int mixture[102];
	long int n,i;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&mixture[i]);
		}
		printf("%ld\n",min_smoke(mixture,1,n-1));
	}
	
	return 0;
}
