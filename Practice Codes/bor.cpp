#include<stdio.h>
 
/*Function to return max sum such that no two elements
 are adjacent */
long long  FindMaxSum(int arr[], int n)
{
  long long incl = arr[0];
  long long  excl = 0;
 long long  excl_new;
  int i;
 
  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;
 
     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }
 
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}
 
/* Driver program to test above function */
 int arr[1000006];
int main()
{

 int n;
scanf("%d",&n);
 for(int i=0;i<n;i++)
 scanf("%d",&arr[i]);
  printf("%lld\n",FindMaxSum(arr, n));
 
  return 0;
}
