#include<stdio.h>
int main(){
int a,i,b,j,e;
	long unsigned int m,c;
	scanf("%d",&a);
	for(i=0;i<a;i++){e=0;
		scanf("%d%d",&b,&c);
		int d[b],f=0,k,x=1;
		k=c;
		for(j=0;j<b;j++){
			scanf("%d",&d[j]);
	if(e<=d[j]){
	if(e==d[j]){
	x++;
	}
	e=d[j];
}
	}
	m=e*(b-1);
	if(x!=b){
	
		for(j=0;j<b;j++){
			
		if(f==0&&d[j]==e)
		f=1;
		else
			c=c+d[j];	
		}
	
	}	if(m==c||((c-m)%b==0&&c>m)||(k%b==0&&x==b))
		printf("Yes\n");
		else 
		printf("No\n");
	}
	return 0;
}
