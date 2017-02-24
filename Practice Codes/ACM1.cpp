#include "bits/stdc++.h"
using namespace std;



int main()
{
int t,x1,x2,y1,y2;
scanf("%d",&t);
for(int i  =0;i<t;i++)
{
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

x2-=x1;
y2-=y1;
x1=0;
y1=0;
if(((x1==x2)&&(y1!=y2))||((y1==y2)&&(x1!=x2)))
{
  if(x1==x2)
  {
if(y1>y2)
{
  printf("down\n");
}
else
{
    printf("up\n");
}

  }
  else
  {
    if(x1>x2)
    {
  printf("left\n");
    }
    else
    {
        printf("right\n");
    }
  }
}
else
{
  printf("sad\n");
}
}
  return 0;
}
