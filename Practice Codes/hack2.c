#include<stdio.h>
int main()
{
 long signed int i,j,k,n;
 int q,t=0;
 char ch;
 scanf("%d",&q);
 
  for(t=0;t<q*2;t++)
 {
     if(t%2==0)
     printf("\n");
     scanf("%c%ld%ld",&ch,&i,&j);
   long signed int sum=0,pro=1;

    for(n=i;n<=j;n++)
    {
        int f=0;
       for(k=2;k<=n/2;k++)
       {
         if(n%k==0)
         {
            f++;
          break;
         }

       }

      if(f==0)
       {
     if(ch=='P')
     printf("%ld ",n);
     else if(ch=='S')
        sum=sum+n;
     else
        pro=pro*n;
       }

    }

if(ch=='S')
{
    sum=sum%1000000007;
 printf("%ld",sum);
}
 else if(ch=='M')
 {
   pro=pro%1000000007;
 printf("%ld",pro);
 }
}
 return 0;
}
