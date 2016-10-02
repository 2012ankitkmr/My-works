#include<stdio.h>
#include<stdlib.h>
int main(){

long signed int t,n,i,dnv=0,grass,j;

long signed int*ptr;
scanf("%ld",&t);
for(i=0;i<t;i++){
scanf("%ld",&n);

grass=0;
ptr=(long int*)calloc(n,sizeof(long int));

for(j=0;j<n;j++)
scanf("%ld",ptr+j);

for(j=0;j<n;j++){
dnv+=*(ptr+j);
if(dnv>0)
grass=grass+dnv;
else
grass=grass-dnv;
}
printf("%ld\n",grass);
dnv=0;
free(ptr);
}

return 0;
}
