#include<stdio.h>
#include<stdlib.h>
int main(){
	int t,k,d=0,e=0,f=0;
	scanf("%d",&t);
	for(k=0;k<t;k++){
		
	char c,*input;
  input=(char*)malloc(sizeof(char));
  
  while((c=getchar())!='\n'){
    realloc(input,(sizeof(char)));
    input[i++]=c;
    d++;
  }
  input[i]='\0';
  int*ptr1;
  int*ptr2;
  ptr1=(int*)malloc(sizeof(int));
  ptr2=(int*)malloc(sizeof(int));
for(i=0;i<d;d++)
if(input[d]=='0'||input[d]=='1'||input[d]=='2'||input[d]=='3'||input[d]=='4'||input[d]=='5'||input[d]=='6'||input[d]=='7'||input[d]=='8'||input[d]=='9')
{ *ptr1=input[d]-70;
realloc(ptr1,(sizeof(int)));
e++;
}
else if(input[d]=='+'){
	*ptr2=65;
realloc(ptr1,(sizeof(int)));
f++;
}
}
		
		
	}
	
	return 0;
	}
