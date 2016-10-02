#include<stdio.h>
#include<stdlib.h>
int main(){
long a,*ptr,i;
scanf("%d",&a);
ptr=(long*)calloc(a,sizeof(long));
for(i=1;i<=a;i++){
    scanf("%d",ptr+i);
   printf(" ");
    }
long c=0,j;
for(i=1;i<=a;i++){
for(j=i;j<a;j++)
 {c=c+(*(ptr+i)&*(ptr+(j+1)));
 }
}
printf("%d",c);
return 0;
}


