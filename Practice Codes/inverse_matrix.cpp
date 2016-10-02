#include<bits/stdc++.h>
using  namespace std;

int main()
{
 int a[3][3],i,j;
 float determinant=0;
 printf("Enter elements of 3x3 matrix:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 printf("\nThe entered matrix is:\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
 for(i=0;i<3;i++)
 {
  determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*
  a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
 }
 if(determinant==0)
 {
  printf("Inverse does not exist (Determinant=0).\n");
 }
 else
 {
  printf("\nInverse of matrix is: \n");
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * 
    a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*
     a[(i+2)%3][(j+1)%3]))/ determinant);
  }
  printf("\n");
  }
 return  0;
}
