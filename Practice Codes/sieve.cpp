#include<bits/stdc++.h>
	bool hash[450];

int main()
{
	memset(hash,1,sizeof hash);
	int n=25;

	int i,j,num;
	if(n>=2)
	{
	
	for(i=2;i<=n;i++)
	{
		if(hash[i])
		{
			 j=2;
	while((num=j*i)<=n)
	{
		hash[num]=0;
		//printf("%d",num);
		j++;
	}
		}
	}
}
	for(i=1;i<=n;i++)	
	{
		if(hash[i])
		printf("%d ",i);
	}
	return 0;
}
