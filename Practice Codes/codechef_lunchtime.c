#include<stdio.h>
#define h 1000
int main(){
	int a,i,b,j,flag,f;
	char ch[h];
	scanf("%d",&a);
	for(i=0;i<a;i++){
	flag=0; f=0;	
		scanf("%d",&b);
		scanf("%s",ch);
		
		for(j=0;j<b;j++){
			if(ch[j]=='I')
			flag=1;
			else if(ch[j]=='Y')
			f=1;
		}
		if(flag==1)
		printf("INDIAN\n");
		else if(f==1)
		printf("NOT INDIAN\n");
		
		else 
		printf("NOT SURE\n");
		
	}
	return 0;
}
