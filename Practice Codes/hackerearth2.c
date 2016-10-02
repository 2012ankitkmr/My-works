#include<stdio.h>
#include<math.h>
int main(){
	int a,i,b;
long unsigned int c;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&b);
		c=pow(b,4)+pow(b,2)+2*b;
		c=c/4;
		printf("%d",c);
			}
return 0;
}
