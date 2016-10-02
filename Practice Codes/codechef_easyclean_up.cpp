#include<stdio.h>
#include<stdlib.h>
int main(){
int a,i,b,c,d,j,k;
int*ptr;
int*ptr1;
scanf("%d",&a);
for(i=0;i<a;i++){
scanf("%d%d",&b,&c);
ptr=(int*)calloc(b,sizeof(int));

for(j=0;j<c;j++)
{
    scanf("%d",&k);
k=k-1;
*(ptr+k)=1;
}
d=0;
ptr1=(int*)calloc(b-c,sizeof(int));
for(j=0;j<b;j++){
    if(*(ptr+j)!=1){
        *(ptr1+d)=j+1;
d++;}
else
    *(ptr+j)=j+1;
}
for(j=0;j<(c-(b-c)/2);j+2){
printf("%d ",*ptr1+j);
}
printf("\n");
for(j=1;j<(b-c)/2;j+2)
{
        printf("%d ",*ptr1+j);
}
}
return 0;
}



