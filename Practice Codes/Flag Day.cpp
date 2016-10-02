#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m,a[100005][3];
	int has[100005];
	memset(has,0,sizeof has);
	int arr[5];
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
scanf("%d%d",&n,&m);
for(int i=0;i<m;i++)
scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

for(int i=0;i<m;i++)
{
	for(int j=0;j<3;j++)
	if(has[a[i][j]])
	{
		arr[has[a[i][j]]]=0;
	//	printf("color=%d\n",a[i][j]);
	}
	
	for(int j=0;j<3;j++)
	{
		if(!has[a[i][j]])
		for(int it=1;it<=3;it++)
		{
		if(arr[it])
		{
		//	printf("%d\n",a[i][j]);
		has[a[i][j]]=arr[it];
		arr[it]=0;
	    break;
      	}
	    }
	}
	
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
}

for(int i=1;i<=n;i++)
printf("%d ",has[i]);
printf("\n");	
	
	return 0;
}
