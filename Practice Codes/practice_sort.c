#include<stdio.h>
#include<stdlib.h>

int main(){

int*ptr;
int i,a,j;
scanf("%d",&a);
ptr=(int*)calloc(a,sizeof(int));

if(ptr==NULL){
printf("memory allocation failed");
exit(1);
}
for(i=0;i<a;i++){
scanf("%d",ptr+i);

}
for(i=0;i<a;i++){

for(j=0;j<i;j++){
if(*(ptr+i)<*(ptr+j))
*(ptr+i)=*(ptr+j);

}

}
for(i=0;i<a;i++){
printf("%d\n",*(ptr+i));

}
return 0;
}
