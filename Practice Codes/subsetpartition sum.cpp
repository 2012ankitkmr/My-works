#include<bits/stdc++.h>
int a[500];

bool subsetsum(int n,int sum)
{
	if(sum==0)
	return true;
	if(n==0&&sum!=0)
	return false;
	if(a[n-1]>sum)
	return subsetsum(n-1,sum);
	
	return subsetsum(n-1,sum)||subsetsum(n-1,sum-a[n-1]);

}

bool isboolpartition(int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	sum+=a[i];
	if(sum%2!=0)
	return false;
	
	return subsetsum(n,sum/2);
	
}
int main()
{
	int n,i;
	for(scanf("%d",&n),i=0;i<n;i++)
	scanf("%d",&a[i]);
	if(isboolpartition(n))
printf("sum exists\n");
else
printf("no\n");
	 
	return 0;
}
