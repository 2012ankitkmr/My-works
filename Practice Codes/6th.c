#include<stdio.h>
#include<string.h>
int main()
{
 int t,i,j,count;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
     j=0;
     count=0;
   char str[100];
   scanf("%s",str);
   while(str[j]!='\0')
   {
      if(str[j]=='B')
        count+=2;
      else if(str[j]=='A'||str[j]=='D'||str[j]=='O'||str[j]=='P'||str[j]=='Q'||str[j]=='R')
        count++;
        else

      j++;
   }
   printf("\n%d",count);

 }
return 0;
}
