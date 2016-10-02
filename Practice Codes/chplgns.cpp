#include <stdio.h>
void me(int arr[],int b[],int low,int mid,int high)
{
	int i,l,m,k,uiui[100000],uiui1[100000];
	i=low;
	l=low;
	m=mid+1;
	while((l<=mid) && (m<=high))
	{
		if(arr[l]<=arr[m])
		{
			uiui[i]=arr[l];
			uiui1[i]=b[l];
			l++;
		}
		else
		{
			uiui[i]=arr[m];
			uiui1[i]=b[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			uiui[i]=arr[k];
			uiui1[i]=b[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			uiui[i]=arr[k];
			uiui1[i]=b[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		arr[k]=uiui[k];
		b[k]=uiui1[k];
	}
}
void MS(int arr[],int b[],int low,int high)
{
	int m;
	if(low<high)
	{
		m=low+(high-low)/2;
		MS(arr,b,low,m);
		MS(arr,b,m+1,high);
		me(arr,b,low,m,high);
	}
}
int main(void) {
	int t,m,arr[100000],b[100000],x,y,i,max,j;
long int n;
for(scanf("%d",&t);t--;)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			max=-1000000001;
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d%d",&x,&y);
				if(x>max)
				{
					max=x;
				}
			}
			arr[i]=max;
			b[i]=i;
		}
		MS(arr,b,0,n-1);
		for(j=0;j<n;j++)
		arr[b[j]]=j;
		for(j=0;j<n;j++)
		printf("%d ",arr[j]);
		printf("\n");
	}
	return 0;
}
