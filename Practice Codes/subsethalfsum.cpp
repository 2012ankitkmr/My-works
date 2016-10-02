#include<bits/stdc++.h>
bool t[10240];
int a[10240];

bool subsethalfsum(int n)
{
	int i,k=0,j;
	for(i=0;i<n;i++)
	k+=a[i];
	memset(t,0,sizeof t);
	t[0]=1;
	for(i=0;i<n;i++)
	{
		for(j=k-a[i];j>=0;j--)
		{
			if(t[j])
			{
				t[j+a[i]]=1;
			}
		}
		
	}
	return t[k/2];
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	if(subsethalfsum(n))
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
