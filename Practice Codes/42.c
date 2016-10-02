#include<stdio.h>
 
int main(){
int a,i; 
scanf("%d",&a);
long unsigned int b[a];
for(i=0;i<a;i++){
	int k,j;
for(j=0;j<a;j++)
   scanf("%d",&b[j]);
int d=0;

 for(k=0;k<a;k++){
 for(j=k;j<a;j++){
if(k!=j){

if(d>b[j]&b[k]);
d=b[j]&b[k];
}}
}
printf("%d",d);
}
return 0;
} 
