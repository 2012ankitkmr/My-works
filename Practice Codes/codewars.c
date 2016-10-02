#include<stdio.h>
#include<string.h>
int main(){
	int i,a,x;
	char b[256];
	char enz[256];
	char c[256];
	char *pch;
	scanf("%d",&a);	
		scanf("%s",b);
		
		for(i=0;i<a;i++){
		scanf("%s",enz);
		if(i==0)
		pch=strtok(b,enz);
		else
		pch=strtok(c,enz);
					
		while(pch!=NULL){
			if(i==0)
			strcat(NULL,pch);
			
			strcat(c,pch);
		}	
		}
		
printf("%s",c);
return 0;
}
