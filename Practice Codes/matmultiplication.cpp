#include<bits/stdc++.h>
using namespace std;

int mat1[12][12],mat2[13][13],res[13][13];
int main()
{
	
	int a,b;
scanf("%d%d",&a,&b);

printf("Enter %d * %d block:\n",a,b);
for(int i=0;i<a;i++)
{
	for(int j=0;j<b;j++)
	{
		scanf("%d",&mat1[i][j]);
	}
	
}
printf("Enter %d * %d block:\n",b,a);
for(int i=0;i<b;i++)
{
	for(int j=0;j<a;j++)
	{
		scanf("%d",&mat2[i][j]);
	}
	
}

for(int i=0;i<a;i++)
{
	for(int j=0;j<b;j++)
	{
		printf("%d ",mat1[i][j]);
	}
	printf("\n");
}
printf("\n");
for(int i=0;i<b;i++)
{
	for(int j=0;j<a;j++)
	{
		printf("%d ",mat2[i][j]);
	}
	printf("\n");
}
int tempsum;
for(int i=0;i<a;i++)
{
	
	for(int j=0;j<a;j++)
	{
		tempsum=0;
		for(int k=0;k<b;k++)
	    tempsum+=(mat1[i][k]*mat2[k][j]);
		res[i][j]=tempsum;
	}
	
}
printf("\n");
for(int i=0;i<a;i++)
{
	for(int j=0;j<a;j++)
	{
		printf("%d ",res[i][j]);
	}
	printf("\n");
}


	
	return 0;
}
