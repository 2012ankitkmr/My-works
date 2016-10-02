#include<stdio.h>
 
int main(){
	int a,i,b,c,f=0,g=0;
 
	scanf("%d",&a);
 
	for(i=0;i<a;i++){
 
		scanf("%d%d",&b,&c);
		if((b-c)>f)
 
		f=b-c;
 
		if((c-b)>g)
 
		g=c-b;
 
	}
 
	if(f>g){
 
		printf("%d %d",1,f);
	}
 	else{printf("%d %d",2,g);
 	}
 	return 0;
 } 

