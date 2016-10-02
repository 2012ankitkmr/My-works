#include<stdio.h>

int main()
{
int a,i,b;
double c;

scanf("%d",&a);

for(i=0;i<a;i++){
scanf("%d",&b);

c=1;
while(b>0){
c=c*b;
b--;
}
printf("%.0lf\n",c);
}
return 0;
}
