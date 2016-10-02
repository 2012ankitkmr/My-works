#include<stdio.h>
void main()
{
int a=10,b,c;
c=b=a;
printf("%d %d %d\n",a,b,c);
b-=a--;
printf("%d %d %d\n",a,b,c);

c-=--a;
printf("%d %d %d\n",a,b,c);

a-=--a;
printf("%d %d %d\n",a,b,c);

a-=--a-a--;
printf("%d %d %d\n",a,b,c);

printf("a=%d\nb=%d\nc=%d\n",a, b ,c);
}
