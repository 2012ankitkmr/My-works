#include<stdio.h>
#include<stdlib.h>
#define
int main(){
int i,b,*ptr,j;
long a;
scanf("%d",&a);
for(i=1;i<=a;i++)
{
scanf("%d",&b);
ptr=(int*)calloc(b,sizeof(int));
for(i=0;i<b;i++)
{
    scanf("%d",ptr+i);
printf(" ");
}
int c=(*(ptr+0)+*(ptr+1));
for(i=0;i<b;i++){
    for(j=(i+1);j<b;j++)
    {if(c>(*(ptr+i))+(*(ptr+j)))
    c=(*(ptr+i)+*(ptr+j));
    }
}
printf("%d",c);
}

return 0;
}

