#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int cnt;

void merge(long int arr[],long int temp[],long int left,long int mid,long int right)
{
    int i=left;
    int j=mid;
    int k=left;
    //printf("(%d,%d,%d)\n",left,mid,right);
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
           cnt+=(mid-i);
           //printf("%d%d\n",mid,i);
        }
    }
    while(i<=mid-1)
    temp[k++]=arr[i++];
    while(j<=right)
    temp[k++]=arr[j++];
    for(int i=left;i<=right;i++)
    arr[i]=temp[i];
    
}
void mergesort(long int arr[],long int temp[],long int left,long int right)
{
    
    if(right>left){
        int mid=(left+right)/2;
        mergesort(arr,temp,left,mid);
        mergesort(arr,temp,mid+1,right);
        merge(arr,temp,left,mid+1,right);
    }
    
}
int main()
{
	int t;
	 long int n,a[30005],i,temp1[30005];
	for(scanf("%d",&t);t--;)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		scanf("%ld",&a[i]);

		mergesort(a,temp1,0,n-1);
		printf("%llu\n",cnt);
	}
	return 0;
}
