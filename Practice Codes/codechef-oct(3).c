#include<stdio.h>
#include<stdlib.h>

void merge(long unsigned int arr[],long signed int l,long signed int m, int r)
{
    long signed int i, j, k;
    long signed int n1 = m - l + 1;
    long signed int n2 =  r - m;

    /* create temp arrays */
    long unsigned int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long signed int arr[],long signed int l,
               long signed int r)
{
    if (l < r)
    {
       long signed int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(){
	int t,i,re,bl,gr,c,m,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    scanf("%d%d%d%d",&re,&bl,&gr,&m);

		c=re+bl+gr;
		printf("c=%d\nb=%d",c,bl);
		long unsigned int all[c];
		for(j=0;j<c;j++)
		scanf("%d",&all[j]);

		mergeSort(all,0,c-1);
		j=c-1;
		while(m>0){
			all[j]=all[j]/2;
			mergeSort(all,0,c-1);
			m--;
		}
		printf("%d",all[j]);
			}
		return 0;
	}


