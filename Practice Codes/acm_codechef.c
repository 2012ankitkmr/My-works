#include<stdio.h>


int main(){
int a,i,j,n,f,b[1005],count;

scanf("%d",&a);
for(i=0;i<a;i++){
count=0;
scanf("%d%d",&n,&f);

for(j=0;j<n;j++){
scanf("%d",&b[j]);
}

for(j=0;j<a;j++)
{ if(b[j]>=f)
count++;

}
printf("%d",count);

}
return 0;
}
