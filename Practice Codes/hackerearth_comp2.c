#include<stdio.h>
#include<math.h>
int main()
{
  long signed int e,j,i,n1,d,n2;
int t,flag;
    scanf("%d",&t);
    char ch;
    for(j=1;j<=t;j++){
    scanf("%c",&ch);
    scanf("%d%d",&n1,&n2);
    d=0;
	e=1;
    for(i=n1+1;i<n2;++i)
  {
      flag=0;
      for(j=2;j<=i/2;++j)
      {
        if(i%j==0)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
    {if(ch=='P')
    printf("%d",i);
    else if(ch=='S')
        d=d+i;
        else if(ch=='M')
            e=e*i;
  }
  }
   if(ch=='S')
      printf("%ld",d);
      else if(ch=='M'){
   e=e%1000000007;
        printf("%ld",e);
  }
  }
  return 0;
}
