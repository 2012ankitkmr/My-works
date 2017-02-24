#include<bits/stdc++.h>
using namespace std;


int a[100005];
long long  merge(int arr[], int temp[], int left, int mid, int right)
{
    long long inv_count = 0;
 
    int i = left; /* i is index for left subarray*/
    int j = mid;  /* i is index for right subarray*/
    int k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above explanation/
              diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

long long  _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid;
	long long inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
 
        inv_count += merge(arr, temp, left, mid+1, right);
    }
 
    return inv_count;
}
 
long long countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

int main()
{
	int t,n,fl;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		fl=0;
		for(int i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			if(abs(a[i]-(i+1))>2)
			{
				fl=1;
			}
		}
		if(fl)
		printf("Not Allowed\n");
		else
		{
			printf("%lld\n",countSwaps(a,n));

		}
		
	}
	
	
	return 0;
}
