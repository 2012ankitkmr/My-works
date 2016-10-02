#include<stdio.h>
#include<string.h>
int main(){
	
	char ch[100000];
	int g[123];
	int t,i,h;
	long int c,j,k,l; 
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",ch);
		l=strlen(ch);
for(j=97;j<123;j++){
	g[j]=0;
	
}
	for(j=0;j<l;j++)
		{ h=ch[j];
			g[h]++;
		}
		c=0;
for(j=97;j<123;j++){
	if(g[j]>0)
	c++;
}

		printf("%d\n",c);
	}
	return 0;
}
