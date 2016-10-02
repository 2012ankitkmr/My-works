#include<stdio.h>

int main(){
	
	long a,i;
	long unsigned int b,c;
	
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%lu",&b);
		c=0;
	while(b>1)	
	{
		b=b/5;
		c=c+b;
}

printf("%lu\n",c);
	}
	
	return 0;	
}
