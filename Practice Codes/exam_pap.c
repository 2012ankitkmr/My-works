#include<stdio.h>
int main()
{
 int M,i;
 float N;
int flag=0,sum=0;
 scanf("%d %f",&M,&N);
 int A[M];
  for(i=0;i<M;i++)
  scanf("%d",&A[i]);
  for(i=0;i<M;i++)
  {
   sum=sum+A[i];
   if(A[i]>N/2+1)
   flag++;
  }
  if(M==N)
  {
   for(i=0;i<M;i++)
   if(A[i]>1)
   flag++;
  }
  if(flag!=0||sum>N)
  printf("NO");
  else if(flag==0)
  printf("YES");
return 0;
}
