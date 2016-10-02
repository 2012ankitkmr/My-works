#include <stdio.h> 
#include<string.h>
int main(){
	int t,len,button,product,length,i,n,counter;
	char string[105];
	for(scanf("%d",&t);t--;){
	
		scanf("%s",string);
	length=strlen(string);
		len=0;
		scanf("%d",&n);
		for(i=0;i<length;i++){
			if(string[i]=='S')
				len++;
			else
				len+=2;
		}
		i=1;
		button=12*n;
		product=0;
		while((i*len)+1<=button)
		{
			counter=button-(i*len+1)+1;
			product=product+counter;
			i++;
		}
		printf("%d\n",product);
	}
	return 0;
}
