#include<stdio.h>

int main()
{
short a,i,b;
long unsigned int c;

scanf("%d",&a);

for(i=0;i<a;i++){
scanf("%d",&b);

c=1;
while(b>0){
c=c*b;
b--;
}
printf("%lu\n",c);
}
return 0;
}

