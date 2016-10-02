#include<stdio.h>
#include<string.h>
int main(){
	
	char ch[100];
	int t,i;
	long int c,count,j,k,l; 
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",ch);
		j=0;
		c=0;
		l=strlen(ch);
		while(j!=l)
		{
				count=1;
			for(k=j+1;k<l;k++){
				if(ch[j]==ch[k])
				{j=k-1;
				break;
				}
				else count++;
			}
			if(count>=c){
				c=count;
			}
			j++;
		}
		
		printf("%d\n",c);
	}
	return 0;
}
